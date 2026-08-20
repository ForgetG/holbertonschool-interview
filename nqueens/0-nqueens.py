#!/usr/bin/python3
"""Solve the N queens problem."""

import sys


def solve_nqueens(n):
    """Find and print all possible solutions for N queens."""
    solutions = []
    columns = set()
    diag1 = set()
    diag2 = set()

    def backtrack(row):
        """Place queens row by row using backtracking."""
        if row == n:
            print(solutions)
            return

        for col in range(n):
            if col in columns:
                continue
            if row - col in diag1:
                continue
            if row + col in diag2:
                continue

            solutions.append([row, col])
            columns.add(col)
            diag1.add(row - col)
            diag2.add(row + col)

            backtrack(row + 1)

            solutions.pop()
            columns.remove(col)
            diag1.remove(row - col)
            diag2.remove(row + col)

    backtrack(0)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve_nqueens(n)
