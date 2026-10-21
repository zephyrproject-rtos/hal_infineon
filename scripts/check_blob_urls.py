#!/usr/bin/env python3
# SPDX-FileCopyrightText: Copyright (c) 2026 Infineon Technologies AG,
# SPDX-FileCopyrightText: or an affiliate of Infineon Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: Apache-2.0
"""Check Zephyr module.yml blob URLs do not use mutable git refs.

A blob URL pinned to a moving ref (master/main, refs/heads/<branch>, or a
"latest" branch) silently invalidates the pinned sha256 when upstream updates
that ref: the file at the URL changes, the recorded sha256 no longer matches,
and blob integrity checks fail. Immutable refs (a full commit SHA, or a fixed
release tag) do not drift.

Usage:
  check_blob_urls.py <module.yml>
  check_blob_urls.py <module.yml> --fail-only-urls-file <file>

With --fail-only-urls-file, only URLs listed in <file> (typically the blob URLs
added or changed by a pull request) cause a failure; any pre-existing mutable
URLs are reported as warnings so the check does not block unrelated changes.

Exit 0 if no in-scope blob URL uses a mutable ref; exit 1 listing the offenders.
Depends only on the Python standard library.
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

_RAW = re.compile(r"/raw/(?P<rest>.+)$")
_RAWGH = re.compile(r"raw\.githubusercontent\.com/[^/]+/[^/]+/(?P<rest>.+)$")
_URL_LINE = re.compile(r"^\s*url:\s*(?P<url>\S+)", re.MULTILINE)


def mutable_ref(url: str) -> str | None:
    """Return the mutable ref if the URL is pinned to one, else None."""
    m = _RAW.search(url) or _RAWGH.search(url)
    if not m:
        return None
    segs = m.group("rest").split("/")
    first = segs[0]
    if first == "refs" and len(segs) >= 3 and segs[1] == "heads":
        return "/".join(segs[:3])
    if first in ("master", "main", "HEAD", "develop", "trunk"):
        return first
    if "latest" in first.lower():
        return first
    return None  # full commit SHA or fixed release tag -> immutable


def main(argv: list[str]) -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("module_yml", help="path to a Zephyr module.yml")
    ap.add_argument(
        "--fail-only-urls-file",
        help="only fail on blob URLs listed in this file (e.g. those added or "
        "changed by the PR); pre-existing mutable URLs are reported as warnings",
    )
    args = ap.parse_args(argv)

    text = Path(args.module_yml).read_text(encoding="utf-8")
    urls = [m.group("url").strip("\"'") for m in _URL_LINE.finditer(text)]

    scope: set[str] | None = None
    if args.fail_only_urls_file:
        p = Path(args.fail_only_urls_file)
        scope = (
            {ln.strip() for ln in p.read_text(encoding="utf-8").splitlines() if ln.strip()}
            if p.is_file()
            else set()
        )

    failures: list[tuple[str, str]] = []
    for url in urls:
        ref = mutable_ref(url)
        if ref is None:
            continue
        if scope is not None and url not in scope:
            print(f"::warning::pre-existing mutable blob ref [{ref}]: {url}")
        else:
            failures.append((ref, url))

    if not failures:
        suffix = " added or changed by this change" if scope is not None else ""
        print(f"OK: no blob URL uses a mutable ref{suffix}.")
        return 0

    print("\nERROR: blob URL(s) pinned to a mutable git ref:")
    for ref, url in failures:
        print(f"  [{ref}] {url}")
    print(
        "\nPin each blob URL to an immutable ref (a full commit SHA, or a fixed\n"
        "release tag) and recompute its sha256, so the pinned blob cannot drift\n"
        "when the upstream branch moves."
    )
    return 1


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
