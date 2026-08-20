#!/usr/bin/python3
"""Parse HTTP logs from stdin and compute metrics."""

import sys


def print_stats(total_size, status_codes):
    """Print accumulated file size and status code counts."""
    print("File size: {}".format(total_size))

    for code in sorted(status_codes):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


def main():
    """Read log lines from stdin and compute statistics."""
    total_size = 0
    line_count = 0
    valid_codes = (200, 301, 400, 401, 403, 404, 405, 500)
    status_codes = {}

    try:
        for line in sys.stdin:
            parts = line.split()

            if len(parts) != 9:
                continue

            try:
                status = int(parts[-2])
                size = int(parts[-1])
            except ValueError:
                continue

            if status not in valid_codes:
                continue

            total_size += size
            status_codes[status] = status_codes.get(status, 0) + 1
            line_count += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        print_stats(total_size, status_codes)
        raise


if __name__ == "__main__":
    main()
