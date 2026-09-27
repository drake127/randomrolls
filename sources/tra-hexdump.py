#!/usr/bin/env python3

"""Convert binary WeiDU .tra strings into human-readable hex notation for git diff."""

import argparse
import re
import sys


TRA_PATTERN = re.compile(rb"~~~~~([\s\S]*?)~~~~~")


def escape_blob(match: re.Match) -> bytes:
    return b"~~~~~" + match.group(1).hex().encode("ascii") + b"~~~~~"


def main() -> None:
    parser = argparse.ArgumentParser(description="Convert binary TRA payloads to hex notation for git diff.")
    parser.add_argument("file", help="Path to .tra file to convert")
    args = parser.parse_args()

    try:
        with open(args.file, "rb") as f:
            data = f.read()
    except OSError as exc:
        sys.stderr.write(f"Error reading {args.file}: {exc}\n")
        sys.exit(1)

    sys.stdout.buffer.write(TRA_PATTERN.sub(escape_blob, data))


if __name__ == "__main__":
    main()
