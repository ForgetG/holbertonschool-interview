#include <stdio.h>
#include "sandpiles.h"

/**
 * is_stable - Checks whether a sandpile is stable
 * @grid: 3x3 sandpile
 *
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}

	return (1);
}

/**
 * print_grid - Prints a 3x3 sandpile
 * @grid: 3x3 sandpile
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * topple - Performs one toppling round
 * @grid: 3x3 sandpile
 */
static void topple(int grid[3][3])
{
	int unstable[3][3] = {{0}};
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				unstable[i][j] = 1;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (unstable[i][j])
			{
				grid[i][j] -= 4;

				if (i > 0)
					grid[i - 1][j]++;
				if (i < 2)
					grid[i + 1][j]++;
				if (j > 0)
					grid[i][j - 1]++;
				if (j < 2)
					grid[i][j + 1]++;
			}
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First 3x3 sandpile
 * @grid2: Second 3x3 sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	while (!is_stable(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}
