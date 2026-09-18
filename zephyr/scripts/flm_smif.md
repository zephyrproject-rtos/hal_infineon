<!--
SPDX-FileCopyrightText: Copyright (c) 2026 Infineon Technologies AG,
SPDX-FileCopyrightText: or an affiliate of Infineon Technologies AG. All rights reserved.

SPDX-License-Identifier: Apache-2.0
-->

# flm_smif.py — SMIF flash-loader inspector / patcher

`flm_smif.py` inspects and patches the external-flash geometry that is baked
into a PSE84 CMSIS `.FLM` flash-loader (the ELF image OpenOCD uses to program
SMIF/QSPI/OSPI NOR flash).

The real per-part geometry does **not** live in the generic CMSIS `DevDscr`
(a fixed 128 MB window); it lives in the `cy_stc_smif_*` structures that the
ModusToolbox™ QSPI Configurator emits. This script finds those structures by
ELF symbol and rewrites only their scalar (numeric) fields in place. Pointer
fields hold runtime-relocation sentinels and are never touched.

## Requirements

- Python 3
- [`pyelftools`](https://github.com/eliben/pyelftools) (`pip install pyelftools`)

## Commands

```
python flm_smif.py dump  <in.FLM> [--slot N]
python flm_smif.py patch <in.FLM> (--cfg <cycfg_qspi_memslot.c> | --cfg-dt <board.dtsi>)
                         -o <out.FLM> [--slot N] [--dt-node <label>] [--sfdp]
```

### `dump`

Decodes and prints the geometry (device size, sector/page sizes, command set,
hybrid regions) for every configured slave slot, or a single `--slot N`.

### `patch`

Rewrites one slot's geometry from a configuration source and writes a new
`.FLM`. If several slots are populated, pick one with `--slot`.

## Configuration sources

| Option | Source | Notes |
|--------|--------|-------|
| `--cfg`    | Generated `cycfg_qspi_memslot.c` | Parsed directly from the QSPI Configurator output. |
| `--cfg-dt` | Zephyr `infineon,smif-nor` devicetree node | The SMIF command set is reconstructed exactly as `drivers/flash/flash_infineon_smif.c` builds it. Use `--dt-node <label>` when the file has more than one node. |

## SFDP vs. static mode

- **static** (default): writes the full command set, sector map and timings
  from the config. Only valid for a slot whose `deviceCfg` command pointers are
  already wired (a Configurator-generated FLM).
- **`--sfdp`**: patches the slot for SFDP runtime discovery — sets the
  chip-select, base address, size and the `DETECT_SFDP` flag, and lets the
  device report its own command set at boot. Required for the SFDP-template
  flash-loader shipped as a hal_infineon blob, whose static command set is
  empty. (Patching such a template statically is refused, since the resulting
  loader would hang.)

## Examples

```bash
# Inspect a shipped flash-loader
python flm_smif.py dump PSE84_SMIF.FLM

# Patch slot 0 for SFDP discovery from a board devicetree node
python flm_smif.py patch PSE84_SMIF.FLM \
    --cfg-dt boards/infineon/kit_pse84_hmi/kit_pse84_hmi_memory_map.dtsi \
    --dt-node ext_flash --slot 0 --sfdp -o PSE84_SMIF.patched.FLM

# Patch statically from Configurator output
python flm_smif.py patch PSE84_SMIF.FLM \
    --cfg cycfg_qspi_memslot.c --slot 0 -o PSE84_SMIF.patched.FLM
```

## Notes and limitations

- `patch` only fails when the config needs **more** hybrid regions than the FLM
  slot pre-allocates; the region array cannot grow through a binary patch.
  Fewer or equal regions are patched in place and `hybridRegionCount` is updated.
- Only scalar fields are modified; struct pointers are left untouched.
- The struct layouts assume `CY_IP_MXSMIF_VERSION >= 2` built with
  `-fshort-enums` (validated byte-for-byte against the shipped FLMs).

## Zephyr build integration

Zephyr boards drive this script through
`boards/infineon/common/flm_patch.cmake`. Building a board with
`-DPATCH_FLM=ON` (or a board that forces it on) patches the SFDP-template FLM
from the board's `infineon,smif-nor` node and points OpenOCD at the result, so
`west flash` programs the external flash exactly as the device requires.
