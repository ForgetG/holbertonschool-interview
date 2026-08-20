#!/usr/bin/python3
"""Read stdin logs and compute metrics."""
import sys


VALID_CODES = [200, 301, 400, 401, 403, 404, 405, 500]


def print_stats(total_size, counts):
    """Print current metrics."""
    print("File size: {}".format(total_size))
    for code in VALID_CODES:
        if counts[code] > 0:
            print("{}: {}".format(code, counts[code]))


def parse_line(line):
    """Parse one log line.

    Returns status code and file size independently.
    """
    parts = line.strip().split()
    status = None
    size = None

    try:
        size = int(parts[-1])
    except IndexError:
        pass
    except (TypeError, ValueError):
        pass

    try:
        status = int(parts[-2])
    except IndexError:
        pass
    except (TypeError, ValueError):
        pass

    return (status, size)


def main():
    """Run log parsing on stdin."""
    total_size = 0
    line_count = 0
    counts = {code: 0 for code in VALID_CODES}

    try:
        for line in sys.stdin:
            line_count += 1

            status, size = parse_line(line)
            if size is not None:
                total_size += size

            if status in counts:
                counts[status] += 1

            if line_count % 10 == 0:
                print_stats(total_size, counts)
    except KeyboardInterrupt:
        print_stats(total_size, counts)
        return

    if line_count == 0 or line_count % 10 != 0:
        print_stats(total_size, counts)


if __name__ == "__main__":
    main()
