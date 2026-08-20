#!/usr/bin/python3
"""Module that calculates the minimum number of operations."""


def minOperations(n):
    """Calculate the minimum operations needed to get n H characters.

    Args:
        n (int): Target number of H characters.

    Returns:
        int: Minimum number of Copy All and Paste operations.
    """
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations
