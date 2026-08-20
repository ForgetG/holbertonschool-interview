#!/usr/bin/python3
"""Parse HTTP logs from stdin and compute metrics."""

import sys


def print_stats(total_size, status_codes):
    """Print accumulated statistics."""
    print("File size: {}".format(total_size))

    for code in sorted(status_codes):
        if status_codes[code]:
            print("{}: {}".format(code, status_codes[code]))


def main():
    """Read stdin line by line and compute log metrics."""
    total_size = 0
    line_count = 0
    valid_codes = (200, 301, 400, 401, 403, 404, 405, 500)
    status_codes = {}

    for code in valid_codes:
        status_codes[code] = 0

    try:
        for line in sys.stdin:
            line_count += 1
            parts = line.split()

            if (len(parts) == 9 and
                    parts[2].startswith("[") and
                    parts[4] == '"GET' and
                    parts[5] == "/projects/260" and
                    parts[6] == 'HTTP/1.1"'):
                try:
                    status = int(parts[7])
                    size = int(parts[8])

                    total_size += size

                    if status in valid_codes:
                        status_codes[status] += 1
                except ValueError:
                    pass

            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        print_stats(total_size, status_codes)


if __name__ == "__main__":
    main()
