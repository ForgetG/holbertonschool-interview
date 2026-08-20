#!/usr/bin/python3
"""Rotate a square 2D matrix 90 degrees clockwise."""


def rotate_2d_matrix(matrix):
    """Rotate an n x n matrix 90 degrees clockwise in-place."""
    size = len(matrix)

    for row in range(size):
        for col in range(row + 1, size):
            matrix[row][col], matrix[col][row] = (
                matrix[col][row], matrix[row][col]
            )

    for row in matrix:
        left = 0
        right = size - 1

        while left < right:
            row[left], row[right] = row[right], row[left]
            left += 1
            right -= 1
