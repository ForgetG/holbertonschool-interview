#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array according to a significant digit
 * @array: Array to sort
 * @size: Size of the array
 * @exp: Current significant digit
 * @buffer: Temporary array
 */
void counting_sort(int *array, size_t size, int exp, int *buffer)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	i = size;
	while (i > 0)
	{
		i--;
		buffer[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - Sorts an array of integers using LSD radix sort
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	int *buffer;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp, buffer);
		print_array(array, size);

		if (exp > max / 10)
			break;
	}

	free(buffer);
}
