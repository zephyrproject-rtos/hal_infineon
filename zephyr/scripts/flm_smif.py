#!/usr/bin/env python3
# SPDX-FileCopyrightText: Copyright (c) 2026 Infineon Technologies AG,
# SPDX-FileCopyrightText: or an affiliate of Infineon Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: Apache-2.0
"""
flm_smif.py  -  Inspect and patch the SMIF (QSPI/OSPI) memory geometry that the
ModusToolbox QSPI Configurator bakes into a CMSIS .FLM flash-loader.

Background
----------
A PSE84 .FLM is an ELF32 CMSIS flash-algorithm image. The per-part flash
geometry is NOT the generic CMSIS `DevDscr` (that is a fixed 128 MB window);
the real geometry lives in the linked `cy_stc_smif_*` structures emitted by the
QSPI Configurator into `cycfg_qspi_memslot.c`. Those structures are located in
the FLM by the ELF symbol table:

    CFGSMIF_deviceCfg_SlaveSlot_<N>     cy_stc_smif_mem_device_cfg_t (124 bytes)
    CFGSMIF_SlaveSlot_<N>_<role>Cmd     cy_stc_smif_mem_cmd_t        (40 bytes)
    CFGSMIF_SlaveSlot_<N>_region<i>     cy_stc_smif_hybrid_region_info_t (20 bytes)
    CFGSMIF_SlaveSlot_<N>               cy_stc_smif_mem_config_t     (36 bytes)

Struct field offsets below were derived from the CAT1 PDL header
(cy_smif_memslot.h, CY_IP_MXSMIF_VERSION >= 2) built with -fshort-enums, and
validated byte-for-byte against the shipped FLMs (cmd=40 B, devcfg=124 B,
region=20 B). Enum fields are 1 byte; uint32/pointer fields are 4 bytes.

Pointer fields in the generated variants hold a runtime-relocation sentinel
(0xdeadbeef / 0x0), so this tool NEVER touches pointers. It locates every
struct directly by symbol and rewrites only scalar (numeric) fields in place.

Usage
-----
    python flm_smif.py dump  <in.FLM> [--slot N]
    python flm_smif.py patch <in.FLM> --cfg cycfg_qspi_memslot.c -o <out.FLM> [--slot N]
                             [--erase-chunk 0x10000] [--program-chunk 0x1000]
                         or --cfg-dt board.dtsi [--dt-node label]

`patch` refuses to run only if the config needs MORE hybrid regions than the
FLM slot reserves (the pre-allocated region array can't grow via a binary
patch). An equal or smaller number of regions is patched in place and
hybridRegionCount is updated to match.

Configuration formats:
    --cfg file.c           Parse generated cycfg_qspi_memslot.c
    --cfg-dt file.dtsi     Parse a Zephyr `infineon,smif-nor` devicetree node
                           (the SMIF command set is reconstructed exactly as
                           the flash_infineon_smif driver builds it)
"""

import argparse
import re
import struct
import sys

# ---------------------------------------------------------------------------
# Validated struct layouts (CY_IP_MXSMIF_VERSION >= 2, -fshort-enums)
# ---------------------------------------------------------------------------

# name -> (offset, byte_width).  Only scalar (patchable) fields are listed.
CMD_FIELDS = {
    "command":             (0,  4),
    "cmdWidth":            (4,  1),
    "addrWidth":           (5,  1),
    "mode":                (8,  4),
    "modeWidth":           (12, 1),
    "dummyCycles":         (16, 4),
    "dataWidth":           (20, 1),
    "dataRate":            (21, 1),
    "dummyCyclesPresence": (22, 1),
    "modePresence":        (23, 1),
    "modeH":               (24, 4),
    "modeRate":            (28, 1),
    "addrRate":            (29, 1),
    "cmdPresence":         (30, 1),
    "commandH":            (32, 4),
    "cmdRate":             (36, 1),
}
CMD_SIZE = 40

DEVCFG_FIELDS = {
    "numOfAddrBytes":       (0,   4),
    "memSize":              (4,   4),
    # +8..+52 are command pointers (never patched)
    "eraseSize":            (24,  4),
    "programSize":          (36,  4),
    "stsRegBusyMask":       (56,  4),
    "stsRegQuadEnableMask": (60,  4),
    "eraseTime":            (64,  4),
    "chipEraseTime":        (68,  4),
    "programTime":          (72,  4),
    "hybridRegionCount":    (76,  4),
    "latencyCyclesRegAddr": (92,  4),
    "latencyCyclesMask":    (96,  4),
    "stsRegOctalEnableMask":(112, 4),
    "octalEnableRegAddr":   (116, 4),
    "freq_of_operation":    (120, 1),
}
DEVCFG_SIZE = 124
DEVCFG_HYBRID_COUNT_OFF = 76

REGION_FIELDS = {
    "regionAddress": (0,  4),
    "sectorsCount":  (4,  4),
    "eraseCmd":      (8,  4),
    "eraseSize":     (12, 4),
    "eraseTime":     (16, 4),
}
REGION_SIZE = 20

# cy_stc_smif_octal_ddr_en_seq_t (CY_SMIF_SFDP_ODDR_CMD_SEQ_MAX_LEN = 8):
# cmdSeq1Len, cmdSeq2Len, then two 8-byte command arrays; validated 18 bytes.
OE_SEQ_LEN_FIELDS = {
    "cmdSeq1Len": (0, 1),
    "cmdSeq2Len": (1, 1),
}
OE_SEQ_MAX_LEN = 8
OE_SEQ_CMD1_OFF = 2
OE_SEQ_CMD2_OFF = 10
OE_SEQ_SIZE = 18

MEMCFG_FIELDS = {
    # In patched flashloaders this is an 8-bit enum field.
    "slaveSelect":  (0,  1),
    # flags is a 32-bit bitmask (CY_SMIF_FLAG_*)
    "flags":        (4,  4),
    "dataSelect":   (8,  1),
    "baseAddress":  (12, 4),
    "memMappedSize":(16, 4),
    "dualQuadSlots":(20, 4),
}

# device-cfg C field name -> FLM symbol role suffix for command structs
CMD_ROLE_SUFFIX = {
    "readCmd": "readCmd",
    "writeEnCmd": "writeEnCmd",
    "writeDisCmd": "writeDisCmd",
    "eraseCmd": "eraseCmd",
    "chipEraseCmd": "chipEraseCmd",
    "programCmd": "programCmd",
    "readStsRegWipCmd": "readStsRegWipCmd",
    "readStsRegQeCmd": "readStsRegQeCmd",
    "writeStsRegQeCmd": "writeStsRegQeCmd",
    "readSfdpCmd": "readSfdpCmd",
    "readLatencyCmd": "readLatencyCmd",
    "writeLatencyCmd": "writeLatencyCmd",
    "readStsRegOeCmd": "readStsRegOeCmd",
    "writeStsRegOeCmd": "writeStsRegOeCmd",
}

# Enum macro -> integer value (for parsing the generated .c)
ENUM_VALUES = {
    "CY_SMIF_WIDTH_SINGLE": 0, "CY_SMIF_WIDTH_DUAL": 1,
    "CY_SMIF_WIDTH_QUAD": 2, "CY_SMIF_WIDTH_OCTAL": 3,
    "CY_SMIF_WIDTH_NA": 0xFF,
    "CY_SMIF_SDR": 0, "CY_SMIF_DDR": 1,
    "CY_SMIF_NOT_PRESENT": 0, "CY_SMIF_PRESENT_1BYTE": 1, "CY_SMIF_PRESENT_2BYTE": 2,
    "CY_SMIF_SLAVE_SELECT_0": 1, "CY_SMIF_SLAVE_SELECT_1": 2,
    "CY_SMIF_SLAVE_SELECT_2": 4, "CY_SMIF_SLAVE_SELECT_3": 8,
    "CY_SMIF_DATA_SEL0": 0, "CY_SMIF_DATA_SEL1": 1,
    "CY_SMIF_DATA_SEL2": 2, "CY_SMIF_DATA_SEL3": 3,
    "CY_SMIF_SLAVE_SELECT_4": 16, "CY_SMIF_SLAVE_SELECT_5": 32,
    "CY_SMIF_SLAVE_SELECT_6": 64, "CY_SMIF_SLAVE_SELECT_7": 128,
    "CY_SMIF_100MHZ_OPERATION": 0,
    "CY_SMIF_133MHZ_OPERATION": 1,
    "CY_SMIF_166MHZ_OPERATION": 2,
    "CY_SMIF_200MHZ_OPERATION": 3,
    "CY_SMIF_FLAG_WR_EN": 0x01,
    "CY_SMIF_FLAG_WRITE_ENABLE": 0x01,
    "CY_SMIF_FLAG_MEMORY_MAPPED": 0x02,
    "CY_SMIF_FLAG_DETECT_SFDP": 0x04,
    "CY_SMIF_FLAG_DETECT_SFDP_SDR_ONLY": 0x40,
    "CY_SMIF_FLAG_CRYPTO_EN": 0x08,
    "CY_SMIF_FLAG_CRYPTO_ENABLE": 0x08,
    "CY_SMIF_FLAG_SMIF_REV_3": 0x10,
    "CY_SMIF_FLAG_MERGE_ENABLE": 0x20,
    "CY_SMIF_FLAG_MERGE_EN": 0x20,
}


# ---------------------------------------------------------------------------
# ELF access
# ---------------------------------------------------------------------------

class Flm:
    def __init__(self, path):
        from elftools.elf.elffile import ELFFile
        self.path = path
        self.data = bytearray(open(path, "rb").read())
        elf = ELFFile(open(path, "rb"))
        self._loadable = []
        for s in elf.iter_sections():
            if s["sh_type"] == "SHT_PROGBITS" and s["sh_addr"] != 0:
                self._loadable.append((s["sh_addr"],
                                       s["sh_addr"] + s["sh_size"],
                                       s["sh_offset"]))
        self.sym = {}
        st = elf.get_section_by_name(".symtab")
        for s in st.iter_symbols():
            if s.name and s.name not in self.sym:
                self.sym[s.name] = s["st_value"]

    def _a2o(self, addr):
        for lo, hi, off in self._loadable:
            if lo <= addr < hi:
                return off + (addr - lo)
        raise KeyError("address 0x%08x not in a loadable section" % addr)

    def sym_off(self, name):
        return self._a2o(self.sym[name])

    def read(self, foff, width):
        fmt = {1: "<B", 2: "<H", 4: "<I"}[width]
        return struct.unpack_from(fmt, self.data, foff)[0]

    def write(self, foff, width, value):
        fmt = {1: "<B", 2: "<H", 4: "<I"}[width]
        struct.pack_into(fmt, self.data, foff, value & ((1 << (8 * width)) - 1))

    def slots(self):
        out = []
        for name in self.sym:
            m = re.fullmatch(r"CFGSMIF_deviceCfg_SlaveSlot_(\d+)", name)
            if m:
                out.append(int(m.group(1)))
        return sorted(out)

    def slot_is_populated(self, n):
        try:
            o = self.sym_off("CFGSMIF_deviceCfg_SlaveSlot_%d" % n)
        except KeyError:
            return False
        return self.read(o + DEVCFG_FIELDS["memSize"][0], 4) != 0

    def has_cmd(self, n, suffix):
        return ("CFGSMIF_SlaveSlot_%d_%s" % (n, suffix)) in self.sym


# ---------------------------------------------------------------------------
# dump
# ---------------------------------------------------------------------------

WIDTH_NAME = {0: "1x", 1: "2x", 2: "4x", 3: "8x"}


def decode_cmd(flm, name):
    o = flm.sym_off(name)
    return {f: flm.read(o + off, w) for f, (off, w) in CMD_FIELDS.items()}


def dump_slot(flm, n):
    dco = flm.sym_off("CFGSMIF_deviceCfg_SlaveSlot_%d" % n)
    dev = {f: flm.read(dco + off, w) for f, (off, w) in DEVCFG_FIELDS.items()}
    print("  device geometry:")
    print("    numOfAddrBytes = %d" % dev["numOfAddrBytes"])
    print("    memSize        = 0x%08x (%d bytes)" % (dev["memSize"], dev["memSize"]))
    print("    eraseSize      = 0x%08x (%d bytes)" % (dev["eraseSize"], dev["eraseSize"]))
    print("    programSize    = 0x%08x (%d bytes)" % (dev["programSize"], dev["programSize"]))
    print("    stsRegBusyMask = 0x%02x   stsRegQuadEnableMask = 0x%02x"
          % (dev["stsRegBusyMask"], dev["stsRegQuadEnableMask"]))
    print("    eraseTime=%dms  chipEraseTime=%dms  programTime=%dus"
          % (dev["eraseTime"], dev["chipEraseTime"], dev["programTime"]))
    try:
        mco = flm.sym_off("CFGSMIF_SlaveSlot_%d" % n)
        base = flm.read(mco + MEMCFG_FIELDS["baseAddress"][0], 4)
        msz = flm.read(mco + MEMCFG_FIELDS["memMappedSize"][0], 4)
        print("    baseAddress    = 0x%08x   memMappedSize = 0x%08x" % (base, msz))
    except KeyError:
        pass

    print("  commands:")
    for suffix in ("readCmd", "writeEnCmd", "eraseCmd", "chipEraseCmd",
                   "programCmd", "readStsRegWipCmd", "readStsRegQeCmd",
                   "writeStsRegQeCmd", "readSfdpCmd"):
        nm = "CFGSMIF_SlaveSlot_%d_%s" % (n, suffix)
        if nm not in flm.sym:
            continue
        c = decode_cmd(flm, nm)
        present = "present" if c["cmdPresence"] else "absent "
        print("    %-17s cmd=0x%02x %s addr=%s data=%s dummy=%-2d mode=0x%x"
              % (suffix, c["command"] & 0xFF, present,
                 WIDTH_NAME.get(c["addrWidth"], "?"),
                 WIDTH_NAME.get(c["dataWidth"], "?"),
                 c["dummyCycles"], c["mode"]))

    hc = dev["hybridRegionCount"]
    if hc:
        print("  hybrid regions (%d):" % hc)
        for i in range(hc):
            nm = "CFGSMIF_SlaveSlot_%d_region%d" % (n, i)
            if nm not in flm.sym:
                print("    region%d: <symbol missing>" % i)
                continue
            ro = flm.sym_off(nm)
            r = {f: flm.read(ro + off, w) for f, (off, w) in REGION_FIELDS.items()}
            print("    region%d: addr=0x%08x count=%-4d eraseCmd=0x%02x "
                  "eraseSize=0x%06x eraseTime=%dms"
                  % (i, r["regionAddress"], r["sectorsCount"], r["eraseCmd"],
                     r["eraseSize"], r["eraseTime"]))
    else:
        print("  hybrid regions: none (uniform sectors)")


def cmd_dump(args):
    flm = Flm(args.flm)
    slots = flm.slots()
    print("FLM: %s" % args.flm)
    print("Configured slots: %s" % ", ".join(str(s) for s in slots))
    targets = [args.slot] if args.slot is not None else slots
    for n in targets:
        pop = flm.slot_is_populated(n)
        print("\n[SlaveSlot_%d]%s" % (n, "" if pop else "  (template / not populated)"))
        dump_slot(flm, n)


# ---------------------------------------------------------------------------
# cycfg_qspi_memslot.c parser
# ---------------------------------------------------------------------------

def _strip_outer_parens(token):
    """Strip one or more balanced outer parenthesis pairs from token."""
    s = token.strip()
    while s.startswith("(") and s.endswith(")"):
        depth = 0
        ok = True
        for i, ch in enumerate(s):
            if ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
                if depth == 0 and i != len(s) - 1:
                    ok = False
                    break
            if depth < 0:
                ok = False
                break
        if not ok or depth != 0:
            break
        s = s[1:-1].strip()
    return s


def _strip_cast_prefix(token):
    """Strip leading C casts like '(type*)' repeatedly."""
    s = token.strip()
    while s.startswith("("):
        m = re.match(r"^\([^\)]*\)\s*", s)
        if not m:
            break
        s = s[m.end():].strip()
    return s


def _normalize_ref_token(token):
    """Normalize a reference token: remove '&', casts, wrapping parens, and [idx]."""
    s = token.strip()
    s = _strip_outer_parens(s)
    s = _strip_cast_prefix(s)
    s = s.lstrip("&").strip()
    s = _strip_outer_parens(s)
    s = re.sub(r"\[[^\]]*\]\s*$", "", s)
    return s.strip()


def _val(token):
    """Convert a C initializer token (including OR expressions) to int, or None."""
    s = token.strip()
    s = _strip_outer_parens(s)
    s = _strip_cast_prefix(s)
    s = _strip_outer_parens(s)

    parts = [p.strip() for p in s.split("|")]
    if len(parts) > 1:
        out = 0
        for p in parts:
            v = _val(p)
            if v is None:
                return None
            out |= v
        return out

    s = s.rstrip("U").rstrip("u")
    if s in ENUM_VALUES:
        return ENUM_VALUES[s]
    try:
        return int(s, 0)
    except ValueError:
        return None


def _parse_block(text, typ, name):
    """Return dict of .field -> raw token string for `typ name = { ... };`."""
    pat = re.compile(
        r"\b" + re.escape(typ) + r"\s+" + re.escape(name) +
        r"\s*=\s*\{(.*?)\}\s*;", re.S)
    m = pat.search(text)
    if not m:
        return None
    body = m.group(1)
    fields = {}
    for fm in re.finditer(r"\.(\w+)\s*=\s*([^,\n]+)", body):
        # First occurrence wins: avoids #if / #else duplicates being overwritten
        if fm.group(1) not in fields:
            fields[fm.group(1)] = fm.group(2).strip()
    return fields


def parse_cfg_c(path):
    """Parse a generated cycfg_qspi_memslot.c into a normalized device model."""
    text = open(path, "r", errors="replace").read()
    # strip // and /* */ comments to simplify token parsing
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    text = re.sub(r"//[^\n]*", " ", text)

    # locate top-level memory config first, then follow .deviceCfg to the device cfg.
    memcfg = {}
    memcfg_name = None
    m = re.search(r"cy_stc_smif_mem_config_t\s+(\w+)\s*=\s*\{", text)
    mblock = None
    if m:
        memcfg_name = m.group(1)
        mblock = _parse_block(text, "cy_stc_smif_mem_config_t", memcfg_name)
        for f in MEMCFG_FIELDS:
            if f in mblock:
                v = _val(mblock[f])
                if v is not None:
                    memcfg[f] = v

    dev_name = None
    if mblock and "deviceCfg" in mblock:
        dev_name = _normalize_ref_token(mblock["deviceCfg"])

    # Fallback: first device cfg in file.
    if not dev_name:
        m = re.search(r"cy_stc_smif_mem_device_cfg_t\s+(\w+)\s*=\s*\{", text)
        if not m:
            raise SystemExit("error: no cy_stc_smif_mem_device_cfg_t found in %s" % path)
        dev_name = m.group(1)

    dev_raw = _parse_block(text, "cy_stc_smif_mem_device_cfg_t", dev_name)
    if dev_raw is None:
        raise SystemExit("error: could not parse device cfg block '%s' in %s" % (dev_name, path))

    device = {}
    for f in DEVCFG_FIELDS:
        if f in dev_raw:
            v = _val(dev_raw[f])
            if v is not None:
                device[f] = v

    # command structs referenced by the device cfg (role -> struct name)
    commands = {}
    for role in CMD_ROLE_SUFFIX:
        raw = dev_raw.get(role)
        if not raw:
            continue
        ref = _normalize_ref_token(raw)
        if ref in ("0", "NULL"):
            continue
        cblock = _parse_block(text, "cy_stc_smif_mem_cmd_t", ref)
        if cblock is None:
            continue
        vals = {}
        for f in CMD_FIELDS:
            if f in cblock:
                v = _val(cblock[f])
                if v is not None:
                    vals[f] = v
        commands[role] = vals

    # hybrid regions: device.hybridRegionInfo names an array of &region pointers
    regions = []
    info_ref = dev_raw.get("hybridRegionInfo", "").strip()
    if info_ref and info_ref not in ("0", "NULL"):
        info_ref = _normalize_ref_token(info_ref)
        arr = re.search(
            r"\b" + re.escape(info_ref) + r"\s*\[[^\]]*\]\s*=\s*\{([^}]*)\}", text)
        if arr:
            names = [_normalize_ref_token(x) for x in arr.group(1).split(",") if x.strip()]
        else:
            names = []
        for rn in names:
            rblock = _parse_block(text, "cy_stc_smif_hybrid_region_info_t", rn)
            if rblock is None:
                continue
            rvals = {}
            for f in REGION_FIELDS:
                if f in rblock:
                    v = _val(rblock[f])
                    if v is not None:
                        rvals[f] = v
            regions.append(rvals)

    return {
        "device": device,
        "commands": commands,
        "regions": regions,
        "memcfg": memcfg,
        "memcfg_name": memcfg_name,
        "device_name": dev_name,
    }


# ---------------------------------------------------------------------------
# Device-tree config (Zephyr `infineon,smif-nor` node)
# ---------------------------------------------------------------------------
#
# A devicetree node describes the memory abstractly; the concrete SMIF command
# structs are built by the Zephyr controller driver
# (drivers/flash/flash_infineon_smif.c, macro IFX_SMIF_CHILD_NOR_DEFINE). This
# parser reconstructs the exact same structs so the FLM matches what the driver
# would program at runtime. For single-spi (1-1-1) and quad-spi (1-4-4 with a
# 1-byte mode) only the read command varies and every other command is
# single-line; octal-spi builds the full 8D-8D-8D command set (two-byte DDR
# commands, OE status commands and an octal-DDR enable sequence).

def _dt_eval(tok):
    """Evaluate a single devicetree cell token (int, DT_SIZE_*, BIT)."""
    tok = tok.strip()
    m = re.fullmatch(r"DT_SIZE_([KMG])\s*\(\s*([0-9A-Fa-fXx]+)\s*\)", tok)
    if m:
        mult = {"K": 1024, "M": 1024 ** 2, "G": 1024 ** 3}[m.group(1)]
        return int(m.group(2), 0) * mult
    m = re.fullmatch(r"BIT\s*\(\s*([0-9A-Fa-fXx]+)\s*\)", tok)
    if m:
        return 1 << int(m.group(1), 0)
    return int(tok, 0)


def _dt_cells(raw):
    """Return the list of integers from one or more <...> cell groups."""
    out = []
    for grp in re.findall(r"<([^>]*)>", raw):
        out += [_dt_eval(t) for t in grp.split() if t]
    return out


def _dt_string(raw):
    m = re.search(r'"([^"]*)"', raw)
    return m.group(1) if m else None


def _dt_strip_nested(body):
    """Remove nested `{...}` child-node blocks, leaving only direct properties."""
    prev = None
    s = body
    while prev != s:
        prev = s
        s = re.sub(r"\{[^{}]*\}", " ", s)
    return s


def _dt_find_nodes(text):
    """Locate every `[label:] name@addr { ... }` node and return its raw body."""
    nodes = []
    for m in re.finditer(r"(?:(\w+)\s*:\s*)?(\w+)@([0-9A-Fa-f]+)\s*\{", text):
        depth = 0
        i = m.end() - 1
        while i < len(text):
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1
                if depth == 0:
                    break
            i += 1
        nodes.append((m.group(1), m.group(3), text[m.end():i]))
    return nodes


def _dt_node_props(body):
    """Parse a node body into {prop: value}; valueless booleans map to ""."""
    direct = _dt_strip_nested(body)
    props = {}
    for pm in re.finditer(r"([#\w,.\-]+)\s*=\s*([^;]+);", direct):
        props[pm.group(1).strip()] = pm.group(2).strip()
    # valueless boolean properties (e.g. `memory-mapped;`, `ranges;`)
    for bm in re.finditer(r"(?:(?<=[\s;{>])|^)([A-Za-z#][\w,.\-]*)\s*;", direct):
        props.setdefault(bm.group(1).strip(), "")
    return props


# SMIF enum integer values (validated against cy_smif.h, -fshort-enums)
_W_SINGLE, _W_QUAD, _W_OCTAL = 0, 2, 3
_W_NA = 0xFF
_SDR, _DDR = 0, 1
_NOT_PRESENT, _PRESENT_1BYTE, _PRESENT_2BYTE = 0, 1, 2
_NO_CMD = 0xFFFFFFFF

# operation-frequency-mhz -> cy_en_smif_interface_freq_t (cy_smif.h)
_FREQ_ENUM = {100: 0, 133: 1, 166: 2, 200: 3}


def _dt_cmd(op, *, width=_W_SINGLE, modew=_W_SINGLE, mode=_NO_CMD, dummy=0,
            dummy_present=_NOT_PRESENT, mode_present=_NOT_PRESENT):
    """Build one cy_stc_smif_mem_cmd_t as the driver's IFX_SMIF_CMD macro does."""
    return {
        "command": op, "commandH": 0,
        "cmdWidth": _W_SINGLE, "cmdRate": _SDR, "cmdPresence": _PRESENT_1BYTE,
        "addrWidth": width, "addrRate": _SDR,
        "mode": mode, "modeH": 0, "modeWidth": modew, "modeRate": _SDR,
        "modePresence": mode_present,
        "dummyCycles": dummy, "dummyCyclesPresence": dummy_present,
        "dataWidth": width, "dataRate": _SDR,
    }


def _dt_octal_cmd(op, *, addr_w, data_w, addr_rate, data_rate, dummy=0,
                  dummy_present=_NOT_PRESENT):
    """Build one octal-DDR cy_stc_smif_mem_cmd_t (driver IFX_SMIF_OCTAL_CMD).

    Every octal command is a two-byte octal DDR command (commandH mirrors the
    low byte, cmdPresence 2-byte, DDR command rate); the per-command address /
    data widths, rates and dummy cycles vary.
    """
    return {
        "command": op, "commandH": op,
        "cmdWidth": _W_OCTAL, "cmdRate": _DDR, "cmdPresence": _PRESENT_2BYTE,
        "addrWidth": addr_w, "addrRate": addr_rate,
        "mode": _NO_CMD, "modeH": 0, "modeWidth": _W_NA, "modeRate": _SDR,
        "modePresence": _NOT_PRESENT,
        "dummyCycles": dummy, "dummyCyclesPresence": dummy_present,
        "dataWidth": data_w, "dataRate": data_rate,
    }


def _dt_bytes(raw):
    """Return the list of bytes from one or more `[..]` bytestring groups."""
    out = []
    for grp in re.findall(r"\[([^\]]*)\]", raw):
        out += [int(t, 16) for t in grp.split() if t]
    return out


def parse_cfg_dt(path, node_sel=None):
    """Parse a Zephyr `infineon,smif-nor` devicetree node into a device model.

    Mirrors drivers/flash/flash_infineon_smif.c: the command set follows the
    `infineon,protocol` enum. single-spi => 1-1-1; quad-spi => 1-4-4 read with a
    1-byte mode and single-line program/erase/status; octal-spi => full 8D-8D-8D
    (two-byte DDR commands, OE status commands and an octal-DDR enable sequence),
    matching IFX_SMIF_CHILD_OCTAL_DDR_DEFINE.
    """
    text = open(path, "r", errors="replace").read()
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    text = re.sub(r"//[^\n]*", " ", text)

    candidates = []
    for label, addr, body in _dt_find_nodes(text):
        props = _dt_node_props(body)
        if "infineon,smif-nor" not in props.get("compatible", ""):
            continue
        candidates.append((label or ("nor@" + addr), addr, props))

    if not candidates:
        raise SystemExit("error: no `infineon,smif-nor` node found in %s" % path)

    if node_sel is not None:
        sel = node_sel.lower()
        chosen = None
        for name, addr, props in candidates:
            if name.lower() == sel or addr.lower() == sel.lstrip("0x"):
                chosen = (name, addr, props)
                break
        if chosen is None:
            raise SystemExit("error: node %r not found; available: %s"
                             % (node_sel, ", ".join(c[0] for c in candidates)))
    elif len(candidates) == 1:
        chosen = candidates[0]
    else:
        raise SystemExit("error: %d `infineon,smif-nor` nodes (%s); specify --dt-node"
                         % (len(candidates), ", ".join(c[0] for c in candidates)))

    name, addr, props = chosen

    # Property names lost their `infineon,` vendor prefix in a later binding
    # revision; accept either spelling so old and new devicetrees both parse.
    def _get(prop):
        if prop in props:
            return props[prop]
        return props.get("infineon," + prop)

    def _has(prop):
        return prop in props or ("infineon," + prop) in props

    def cells(prop):
        raw = _get(prop)
        if raw is None:
            raise SystemExit("error: node %s missing required property '%s'" % (name, prop))
        return _dt_cells(raw)

    def cell1(prop):
        return cells(prop)[0]

    reg = cells("reg")
    base, size = reg[0], reg[1]

    def bytelist(prop):
        raw = _get(prop)
        if raw is None:
            raise SystemExit("error: node %s missing required property '%s'" % (name, prop))
        return _dt_bytes(raw)

    protocol = _dt_string(_get("protocol") or '"quad-spi"')
    single = (protocol == "single-spi")
    octal = (protocol == "octal-spi")

    device = {
        "numOfAddrBytes": cell1("address-bytes"),
        "memSize": size,
        "eraseSize": cell1("erase-block-size"),
        "programSize": cell1("page-size"),
        "stsRegBusyMask": 0x01,
        "stsRegQuadEnableMask": 0x02,
        "eraseTime": cell1("erase-time-ms"),
        "chipEraseTime": cell1("chip-erase-time-ms"),
        "programTime": cell1("program-time-us"),
    }

    oe_seq = None
    if octal:
        # Octal DDR (8D-8D-8D): mirror driver IFX_SMIF_CHILD_OCTAL_DDR_DEFINE.
        oe_dummy = (cell1("read-status-oe-dummy-cycles")
                    if _has("read-status-oe-dummy-cycles") else 3)
        wip_dummy = (cell1("read-status-wip-dummy-cycles")
                     if _has("read-status-wip-dummy-cycles") else 3)
        commands = {
            "readCmd": _dt_octal_cmd(cell1("read-command"), addr_w=_W_OCTAL,
                                     data_w=_W_OCTAL, dummy=cell1("read-dummy-cycles"),
                                     dummy_present=_PRESENT_1BYTE,
                                     addr_rate=_DDR, data_rate=_DDR),
            "writeEnCmd": _dt_octal_cmd(0x06, addr_w=_W_NA, data_w=_W_NA,
                                        addr_rate=_SDR, data_rate=_SDR),
            "writeDisCmd": _dt_octal_cmd(0x04, addr_w=_W_NA, data_w=_W_NA,
                                         addr_rate=_SDR, data_rate=_SDR),
            "eraseCmd": _dt_octal_cmd(cell1("erase-command"), addr_w=_W_OCTAL,
                                      data_w=_W_NA, addr_rate=_DDR, data_rate=_SDR),
            "chipEraseCmd": _dt_octal_cmd(0x60, addr_w=_W_NA, data_w=_W_NA,
                                          addr_rate=_SDR, data_rate=_SDR),
            "programCmd": _dt_octal_cmd(cell1("program-command"), addr_w=_W_OCTAL,
                                        data_w=_W_OCTAL, addr_rate=_DDR, data_rate=_DDR),
            "readStsRegWipCmd": _dt_octal_cmd(0x05, addr_w=_W_OCTAL, data_w=_W_OCTAL,
                                              dummy=wip_dummy, dummy_present=_PRESENT_1BYTE,
                                              addr_rate=_DDR, data_rate=_DDR),
            "readStsRegOeCmd": _dt_octal_cmd(cell1("read-status-oe-command"),
                                             addr_w=_W_OCTAL, data_w=_W_OCTAL,
                                             dummy=oe_dummy, dummy_present=_PRESENT_1BYTE,
                                             addr_rate=_DDR, data_rate=_DDR),
            "writeStsRegOeCmd": _dt_octal_cmd(cell1("write-status-oe-command"),
                                              addr_w=_W_OCTAL, data_w=_W_NA,
                                              addr_rate=_DDR, data_rate=_SDR),
        }
        device["octalEnableRegAddr"] = cell1("octal-enable-address")
        device["stsRegOctalEnableMask"] = (
            cell1("octal-enable-mask") if _has("octal-enable-mask") else 0x01)
        freq = (cell1("operation-frequency-mhz")
                if _has("operation-frequency-mhz") else 100)
        device["freq_of_operation"] = _FREQ_ENUM.get(freq, 0)
        oe_seq = {
            "cmdSeq1": bytelist("octal-ddr-enable-seq-1"),
            "cmdSeq2": bytelist("octal-ddr-enable-seq-2"),
        }
    else:
        xfer = _W_SINGLE if single else _W_QUAD
        commands = {
            "readCmd": _dt_cmd(cell1("read-command"), width=xfer, modew=xfer,
                               mode=(_NO_CMD if single else 0x01),
                               dummy=cell1("read-dummy-cycles"),
                               dummy_present=_PRESENT_1BYTE,
                               mode_present=(_NOT_PRESENT if single else _PRESENT_1BYTE)),
            "writeEnCmd": _dt_cmd(0x06),
            "writeDisCmd": _dt_cmd(0x04),
            "eraseCmd": _dt_cmd(cell1("erase-command")),
            "chipEraseCmd": _dt_cmd(0x60),
            "programCmd": _dt_cmd(cell1("program-command")),
            "readStsRegWipCmd": _dt_cmd(0x05),
            "readStsRegQeCmd": _dt_cmd(0x35),
            "writeStsRegQeCmd": _dt_cmd(0x01),
        }

    regions = []
    if _has("hybrid-region-address"):
        raddr = cells("hybrid-region-address")
        rcnt = cells("hybrid-region-sectors")
        rcmd = cells("hybrid-region-erase-command")
        rsize = cells("hybrid-region-erase-size")
        rtime = cells("hybrid-region-erase-time-ms")
        for i in range(len(raddr)):
            regions.append({
                "regionAddress": raddr[i],
                "sectorsCount": rcnt[i],
                "eraseCmd": rcmd[i],
                "eraseSize": rsize[i],
                "eraseTime": rtime[i],
            })
    device["hybridRegionCount"] = len(regions)

    # Mirror the driver's mem_cfg flags: SMIF_REV_3 | WR_EN, plus MEMORY_MAPPED
    # when the `memory-mapped` boolean property is present.
    flags = ENUM_VALUES["CY_SMIF_FLAG_SMIF_REV_3"] | ENUM_VALUES["CY_SMIF_FLAG_WR_EN"]
    if _has("memory-mapped"):
        flags |= ENUM_VALUES["CY_SMIF_FLAG_MEMORY_MAPPED"]
    if octal:
        flags |= ENUM_VALUES["CY_SMIF_FLAG_MERGE_ENABLE"]

    memcfg = {"baseAddress": base, "memMappedSize": size, "flags": flags}
    if _has("data-select"):
        memcfg["dataSelect"] = cell1("data-select")

    return {
        "device": device,
        "commands": commands,
        "regions": regions,
        "memcfg": memcfg,
        "oe_seq": oe_seq,
        "memcfg_name": "%s_config" % name,
        "device_name": "deviceCfg_%s" % name,
    }


def load_config(args):
    """Load config from --cfg or --cfg-dt."""
    if args.cfg:
        return parse_cfg_c(args.cfg)
    elif args.cfg_dt:
        return parse_cfg_dt(args.cfg_dt, args.dt_node)
    else:
        raise SystemExit("error: one of --cfg or --cfg-dt is required")


# ---------------------------------------------------------------------------
# patch
# ---------------------------------------------------------------------------

def cmd_patch(args):
    flm = Flm(args.flm)
    model = load_config(args)

    # choose target slot
    populated = [s for s in flm.slots() if flm.slot_is_populated(s)]
    if args.slot is not None:
        slot = args.slot
    elif len(populated) == 1:
        slot = populated[0]
    else:
        raise SystemExit(
            "error: %d populated slots (%s); specify --slot N"
            % (len(populated), ", ".join(map(str, populated)) or "none"))
    if ("CFGSMIF_deviceCfg_SlaveSlot_%d" % slot) not in flm.sym:
        raise SystemExit("error: slot %d not present in FLM" % slot)

    print("Target : %s  ->  slot %d" % (args.flm, slot))
    print("Config : %s" % (args.cfg or args.cfg_dt))
    if model.get("memcfg_name"):
        print("Model  : memcfg=%s deviceCfg=%s" % (model.get("memcfg_name"), model.get("device_name")))

    # SFDP mode patches the slot for runtime discovery (this template's static
    # command pointers are NULL and stay so); static mode writes the full command
    # set and needs a slot whose deviceCfg pointers are already wired.
    sfdp = getattr(args, "sfdp", False)
    readcmd_ptr = flm.read(
        flm.sym_off("CFGSMIF_deviceCfg_SlaveSlot_%d" % slot) + 8, 4)
    if sfdp:
        print("Mode   : SFDP (runtime discovery; command set read from the device)")
    else:
        print("Mode   : static (command set from devicetree)")
        if readcmd_ptr == 0:
            raise SystemExit(
                "error: slot %d in this FLM is an SFDP template (deviceCfg command\n"
                "pointers are NULL), so static command patching has no effect and the\n"
                "resulting loader would hang. Re-run with --sfdp to patch the slot for\n"
                "SFDP runtime discovery, or use a configurator-generated static FLM."
                % slot)

    # ---- capacity check -------------------------------------------------
    # The flashloader template pre-allocates a fixed number of hybrid-region
    # structs per slot (CFGSMIF_SlaveSlot_<slot>_region<N>, typically 16).
    # Like the qspi-configurator elfpatcher, we can populate up to that many
    # regions and update hybridRegionCount in place: the SMIF driver gates on
    # the count (and per-slot region symbols), not on the hybridRegionInfo
    # pointer (which stays null even in the official tool's output). Only a
    # config that needs MORE regions than the template reserves requires a
    # project rebuild.
    dco = flm.sym_off("CFGSMIF_deviceCfg_SlaveSlot_%d" % slot)
    flm_hyb = flm.read(dco + DEVCFG_HYBRID_COUNT_OFF, 4)
    cfg_hyb = model["device"].get("hybridRegionCount", len(model["regions"]))
    region_capacity = 0
    while ("CFGSMIF_SlaveSlot_%d_region%d" % (slot, region_capacity)) in flm.sym:
        region_capacity += 1
    if cfg_hyb > region_capacity:
        raise SystemExit(
            "SHAPE MISMATCH: config needs %d hybrid region(s) but FLM slot %d "
            "only reserves %d.\nThe region array can't grow via binary patch; "
            "rebuild the flash-loader project instead."
            % (cfg_hyb, slot, region_capacity))
    if cfg_hyb != flm_hyb:
        print("  hybridRegionCount %d -> %d (template reserves %d)"
              % (flm_hyb, cfg_hyb, region_capacity))

    # warn about command-role presence differences (non-fatal)
    for role in model["commands"]:
        suffix = CMD_ROLE_SUFFIX[role]
        if not flm.has_cmd(slot, suffix):
            print("  warning: config defines %s but FLM slot has no such command "
                  "struct; skipping" % role)

    changes = []  # (where, field, old, new)

    def patch_struct(sym_name, fields_map, values, where):
        base = flm.sym_off(sym_name)
        for f, newv in values.items():
            if f not in fields_map:
                continue
            off, w = fields_map[f]
            old = flm.read(base + off, w)
            if old != (newv & ((1 << (8 * w)) - 1)):
                flm.write(base + off, w, newv)
                changes.append((where, f, old, newv))

    # ---- device cfg -----------------------------------------------------
    # In SFDP mode only the geometry is set (the device reports its command set
    # via SFDP at runtime); static mode writes every scalar field.
    if sfdp:
        dev_vals = {k: model["device"][k]
                    for k in ("memSize", "eraseSize", "programSize")
                    if k in model["device"]}
    else:
        dev_vals = model["device"]
    patch_struct("CFGSMIF_deviceCfg_SlaveSlot_%d" % slot,
                 DEVCFG_FIELDS, dev_vals, "deviceCfg")

    # ---- memory config (base / mapped size) -----------------------------
    if model["memcfg"] and ("CFGSMIF_SlaveSlot_%d" % slot) in flm.sym:
        # Override slaveSelect based on target slot (per elfpatcher: slaveSelect = 1U << (slot_index % 4))
        memcfg_patched = model["memcfg"].copy()
        memcfg_patched["slaveSelect"] = 1 << (slot % 4)
        if sfdp:
            # Enable SFDP discovery; keep MEMORY_MAPPED when the device is XIP.
            f = (ENUM_VALUES["CY_SMIF_FLAG_SMIF_REV_3"]
                 | ENUM_VALUES["CY_SMIF_FLAG_WR_EN"]
                 | ENUM_VALUES["CY_SMIF_FLAG_DETECT_SFDP"])
            if memcfg_patched.get("flags", 0) & ENUM_VALUES["CY_SMIF_FLAG_MEMORY_MAPPED"]:
                f |= ENUM_VALUES["CY_SMIF_FLAG_MEMORY_MAPPED"]
            memcfg_patched["flags"] = f
        patch_struct("CFGSMIF_SlaveSlot_%d" % slot,
                     MEMCFG_FIELDS, memcfg_patched, "memConfig")

    # ---- patch flashloader chunk globals where present -------------------
    # Erase chunk can be inferred reasonably from eraseSize for many loaders.
    erase_chunk = args.erase_chunk if args.erase_chunk is not None else model["device"].get("eraseSize")
    # Program chunk cannot be inferred safely from cycfg_qspi_memslot.c; only patch when explicitly provided.
    program_chunk = args.program_chunk
    if erase_chunk is not None and "CFGALGO_EraseChunkSize" in flm.sym:
        patch_struct("CFGALGO_EraseChunkSize", {"value": (0, 4)}, {"value": erase_chunk}, "CFGALGO")
    # FlashDevice is optional in newer flashloaders; patch when present.
    if "FlashDevice" in flm.sym:
        fd_fields = {}
        if program_chunk is not None:
            # FlashDevice.szPage
            fd_fields["szPage"] = (140, 4)
        if erase_chunk is not None:
            # FlashDevice.sectors[0] and sentinel sectors[1]
            fd_fields["sector0_size"] = (160, 4)
            fd_fields["sector0_addr"] = (164, 4)
            fd_fields["sector1_size"] = (168, 4)
            fd_fields["sector1_addr"] = (172, 4)
        fd_vals = {}
        if program_chunk is not None:
            fd_vals["szPage"] = program_chunk
        if erase_chunk is not None:
            fd_vals["sector0_size"] = erase_chunk
            fd_vals["sector0_addr"] = 0
            fd_vals["sector1_size"] = 0xFFFFFFFF
            fd_vals["sector1_addr"] = 0xFFFFFFFF
        patch_struct("FlashDevice", fd_fields, fd_vals, "FlashDevice")

    # ---- command structs (skipped in SFDP mode) -------------------------
    for role, vals in ({} if sfdp else model["commands"]).items():
        suffix = CMD_ROLE_SUFFIX[role]
        sym_name = "CFGSMIF_SlaveSlot_%d_%s" % (slot, suffix)
        if sym_name in flm.sym:
            patch_struct(sym_name, CMD_FIELDS, vals, suffix)

    # ---- octal-DDR enable sequence --------------------------------------
    # The octal enable sequence lives in its own struct symbol (not reachable
    # through CMD_ROLE_SUFFIX); patch its lengths and both 8-byte command
    # arrays, zero-filling the unused tail of each array.
    oe_seq = model.get("oe_seq")
    oe_sym = "CFGSMIF_oe_sequence_SlaveSlot_%d" % slot
    if oe_seq and not sfdp and oe_sym in flm.sym:
        oe_base = flm.sym_off(oe_sym)
        s1 = oe_seq["cmdSeq1"][:OE_SEQ_MAX_LEN]
        s2 = oe_seq["cmdSeq2"][:OE_SEQ_MAX_LEN]
        for field, val in (("cmdSeq1Len", len(s1)), ("cmdSeq2Len", len(s2))):
            off, w = OE_SEQ_LEN_FIELDS[field]
            old = flm.read(oe_base + off, w)
            if old != val:
                flm.write(oe_base + off, w, val)
                changes.append(("oe_seq", field, old, val))
        for i in range(OE_SEQ_MAX_LEN):
            for label, seq, arr_off in (("cmdSeq1", s1, OE_SEQ_CMD1_OFF),
                                        ("cmdSeq2", s2, OE_SEQ_CMD2_OFF)):
                val = seq[i] if i < len(seq) else 0
                off = arr_off + i
                old = flm.read(oe_base + off, 1)
                if old != val:
                    flm.write(oe_base + off, 1, val)
                    changes.append(("oe_seq", "%s[%d]" % (label, i), old, val))

    # ---- hybrid regions -------------------------------------------------
    for i, rvals in enumerate([] if sfdp else model["regions"]):
        sym_name = "CFGSMIF_SlaveSlot_%d_region%d" % (slot, i)
        if sym_name in flm.sym:
            patch_struct(sym_name, REGION_FIELDS, rvals, "region%d" % i)

    # ---- dual-quad slot compaction (optional) ----------------------------
    # If --compact-slots is set and dualQuadSlots is defined in memcfg,
    # also patch the paired slot(s) to reflect the new slaveSelect bitfield.
    if args.compact_slots and model["memcfg"].get("dualQuadSlots"):
        dual_quad = model["memcfg"]["dualQuadSlots"]
        # dualQuadSlots is a bitmask of slot indices involved (e.g., 0x3 = slots 0,1)
        for other_slot in range(8):
            if (dual_quad & (1 << other_slot)) and other_slot != slot:
                # Found a paired slot; update its slaveSelect to match position within instance
                # per elfpatcher logic: slaveSelect = (1U << (src_slot % 4))
                # For simplicity, we'll set it to match the peer's position
                new_slave_select = 1 << (other_slot % 4)
                if ("CFGSMIF_SlaveSlot_%d" % other_slot) in flm.sym:
                    mco = flm.sym_off("CFGSMIF_SlaveSlot_%d" % other_slot)
                    old_ss = flm.read(mco + MEMCFG_FIELDS["slaveSelect"][0], 1)
                    if old_ss != new_slave_select:
                        flm.write(mco + MEMCFG_FIELDS["slaveSelect"][0], 1, new_slave_select)
                        changes.append(("memConfig", "slaveSelect_slot%d" % other_slot, old_ss, new_slave_select))

    # ---- report ---------------------------------------------------------
    if not changes:
        print("\nNo scalar differences; output equals input.")
    else:
        print("\n%d field(s) changed:" % len(changes))
        for where, f, old, new in changes:
            print("  [%-11s] %-22s 0x%-10x -> 0x%x" % (where, f, old, new))

    open(args.out, "wb").write(flm.data)
    print("\nWrote %s" % args.out)


# ---------------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)

    d = sub.add_parser("dump", help="decode SMIF geometry from an FLM")
    d.add_argument("flm")
    d.add_argument("--slot", type=int, default=None)
    d.set_defaults(func=cmd_dump)

    p = sub.add_parser("patch", help="patch FLM geometry from a cycfg .c or devicetree")
    p.add_argument("flm")
    cfg_group = p.add_mutually_exclusive_group(required=True)
    cfg_group.add_argument("--cfg", help="cycfg_qspi_memslot.c")
    cfg_group.add_argument("--cfg-dt", help="Zephyr devicetree (.dts/.dtsi) with an infineon,smif-nor node")
    p.add_argument("--dt-node", default=None,
                   help="devicetree node label or unit-address to use when --cfg-dt has several")
    p.add_argument("-o", "--out", required=True)
    p.add_argument("--slot", type=int, default=None)
    p.add_argument("--sfdp", action="store_true",
                   help="patch the slot for SFDP runtime discovery (set DETECT_SFDP "
                        "plus chip-select/base/size/geometry) instead of a static "
                        "command set; required for SFDP-template flashloaders whose "
                        "static config is empty")
    p.add_argument("--erase-chunk", type=lambda s: int(s, 0), default=None,
                   help="optional CFGALGO/FlashDevice erase chunk override")
    p.add_argument("--program-chunk", type=lambda s: int(s, 0), default=None,
                   help="optional FlashDevice page/program chunk override")
    p.add_argument("--compact-slots", action="store_true",
                   help="apply dual-quad slot compaction (patches secondary slot metadata)")
    p.set_defaults(func=cmd_patch)

    args = ap.parse_args()
    args.func(args)


if __name__ == "__main__":
    main()
