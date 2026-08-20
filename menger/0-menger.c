#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * is_hole - Checks whether a position is empty in a Menger sponge
 * @row: Row position
 * @col: Column position
 *
 * Return: 1 if the position is empty, otherwise 0
 */
int is_hole(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);

		row /= 3;
		col /= 3;
	}

	return (0);
}

/**
 * menger - Draws a 2D Menger sponge
 * @level: Level of the Menger sponge
 *
 * Return: Nothing
 */
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = (int)pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (is_hole(row, col))
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}
