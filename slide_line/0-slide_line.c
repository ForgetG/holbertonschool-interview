#include "slide_line.h"

/**
 * slide_left - Slides and merges a line to the left
 * @line: Pointer to the array
 * @size: Number of elements in the array
 */
static void slide_left(int *line, size_t size)
{
	size_t read, write;

	write = 0;

	for (read = 0; read < size; read++)
	{
		if (line[read] == 0)
			continue;

		if (write > 0 && line[write - 1] == line[read])
		{
			line[write - 1] *= 2;
		}
		else
		{
			line[write] = line[read];
			write++;
		}
	}

	while (write < size)
	{
		line[write] = 0;
		write++;
	}
}

/**
 * slide_right - Slides and merges a line to the right
 * @line: Pointer to the array
 * @size: Number of elements in the array
 */
static void slide_right(int *line, size_t size)
{
	size_t read, write;

	write = size;

	for (read = size; read > 0; read--)
	{
		if (line[read - 1] == 0)
			continue;

		if (write < size && line[write] == line[read - 1])
		{
			line[write] *= 2;
		}
		else
		{
			write--;
			line[write] = line[read - 1];
		}
	}

	while (write > 0)
	{
		write--;
		line[write] = 0;
	}
}

/**
 * slide_line - Slides and merges an array like a 2048 line
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: Direction in which to slide
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL)
		return (0);

	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else if (direction == SLIDE_RIGHT)
		slide_right(line, size);
	else
		return (0);

	return (1);
}
