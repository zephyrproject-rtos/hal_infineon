#!/usr/bin/env python3
# SPDX-FileCopyrightText: Copyright (c) 2026 Infineon Technologies AG,
# SPDX-FileCopyrightText: or an affiliate of Infineon Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: Apache-2.0
"""Check the blob declarations in zephyr/module.yml.

Two rules are enforced:

  1. Every blob must be hosted under an Infineon GitHub organisation. A few
     entries predate this rule and are listed in HOST_EXCEPTIONS; nothing new
     may be added to that list.

  2. Every blob a pull request adds or changes must reference its content by
     git commit hash. Tags and branches move, so the bytes behind the url can
     change under us. Most existing entries still point at release tags, so
     this rule only applies to what a pull request touches.

Usage:
    check_blobs.py <base-ref> <head-ref>   # check a pull request
    check_blobs.py                         # check the working tree only
"""

import re
import subprocess
import sys
from urllib.parse import urlsplit

import yaml

MODULE_YML = "zephyr/module.yml"

# GitHub organisations the blobs may be hosted under, lower case.
ALLOWED_ORGS = {"infineon"}

# Hosts that serve GitHub content, mapped to the path index of the owner.
# https://github.com/<owner>/<repo>/raw/<ref>/<path>
# https://raw.githubusercontent.com/<owner>/<repo>/<ref>/<path>
ALLOWED_HOSTS = {"github.com", "raw.githubusercontent.com", "www.github.com"}

# Blob paths allowed to sit outside ALLOWED_ORGS because they were added
# before rule 1 existed. Do not grow this list.
HOST_EXCEPTIONS = {
    "flashloader/TARGET_CYW920829M2EVK-02/CYW208xx_SMIF_64K.FLM",
}

COMMIT_RE = re.compile(r"\A[0-9a-f]{40}\Z")
SHA256_RE = re.compile(r"\A[0-9a-f]{64}\Z")


def git(*args):
    return subprocess.run(
        ["git", *args], check=True, capture_output=True, text=True
    ).stdout


def load_blobs(ref):
    """Return {path: blob} from MODULE_YML at ref, or from disk if ref is None."""
    if ref is None:
        with open(MODULE_YML) as f:
            text = f.read()
    else:
        text = git("show", f"{ref}:{MODULE_YML}")

    doc = yaml.safe_load(text) or {}
    blobs = doc.get("blobs") or []
    return {b.get("path"): b for b in blobs if isinstance(b, dict)}


def split_url(url):
    """Return (host, owner, ref) for a GitHub content url, ref may be None."""
    parts = urlsplit(url)
    segments = [s for s in parts.path.split("/") if s]
    host = parts.netloc.lower()

    owner = segments[0] if segments else None

    ref = None
    if host == "raw.githubusercontent.com":
        # <owner>/<repo>/<ref>/<path...>
        if len(segments) >= 3:
            ref = segments[2]
    elif len(segments) >= 4 and segments[2] in ("raw", "blob"):
        # <owner>/<repo>/raw/<ref>/<path...>, where <ref> is either a bare
        # name or the long refs/heads/<branch> and refs/tags/<tag> form.
        if segments[3] == "refs" and len(segments) >= 6:
            ref = "/".join(segments[3:6])
        else:
            ref = segments[3]

    return host, owner, ref


def check_host(path, blob, errors):
    url = blob.get("url")
    if not url:
        errors.append(f"{path}: no url")
        return

    host, owner, _ = split_url(url)

    if host not in ALLOWED_HOSTS:
        errors.append(f"{path}: url host {host!r} is not a GitHub host ({url})")
        return

    if owner is None or owner.lower() not in ALLOWED_ORGS:
        errors.append(
            f"{path}: url is not under an Infineon organisation "
            f"(owner {owner!r}): {url}"
        )


def check_pinned(path, blob, errors):
    url = blob.get("url")
    if not url:
        errors.append(f"{path}: no url")
        return

    _, _, ref = split_url(url)

    if ref is None:
        errors.append(
            f"{path}: cannot tell which git ref the url points at, so it "
            f"cannot be pinned to a commit: {url}"
        )
    elif not COMMIT_RE.match(ref):
        errors.append(
            f"{path}: url points at {ref!r}, which is a tag or branch and can "
            f"move. Use the full 40 character commit hash instead: {url}"
        )

    sha256 = str(blob.get("sha256", ""))
    if not SHA256_RE.match(sha256):
        errors.append(
            f"{path}: sha256 must be 64 lower case hex characters, got {sha256!r}"
        )


def main(argv):
    if len(argv) == 3:
        base, head = argv[1], argv[2]
    elif len(argv) == 1:
        base, head = None, None
    else:
        print(__doc__, file=sys.stderr)
        return 2

    head_blobs = load_blobs(head)
    base_blobs = load_blobs(base) if base is not None else {}

    errors = []

    # Rule 1 applies to every blob, so a bad host cannot slip in by editing an
    # entry the pull request does not otherwise touch.
    for path, blob in sorted(head_blobs.items()):
        if path in HOST_EXCEPTIONS:
            continue
        check_host(path, blob, errors)

    # Rule 2 applies to what changed, so there is nothing to do without a base
    # to compare against.
    touched = []
    if base is not None:
        touched = sorted(
            path for path, blob in head_blobs.items() if base_blobs.get(path) != blob
        )
        for path in touched:
            check_pinned(path, head_blobs[path], errors)

    print(f"{len(head_blobs)} blobs declared, {len(touched)} added or changed.")
    for path in touched:
        print(f"  {path}")

    if errors:
        print(f"\nERROR: {len(errors)} problem(s) found:", file=sys.stderr)
        for error in errors:
            print(f"  {error}", file=sys.stderr)
        return 1

    if base is None:
        print("OK: all blobs are hosted under Infineon.")
    else:
        print("OK: all blobs are hosted under Infineon, and every blob this "
              "change touches is pinned to a commit.")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
