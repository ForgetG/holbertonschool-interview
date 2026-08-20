#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sorted subarrays
 * @array: Array to sort
 * @buffer: Temporary buffer
 * @left: Start index of the subarray
 * @middle: End index of the left subarray
 * @right: End index of the subarray
 */
void merge(int *array, int *buffer, size_t left,
	   size_t middle, size_t right)
{
	size_t i = left, j = middle, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	while (i < middle && j < right)
	{
		if (array[i] <= array[j])
			buffer[k++] = array[i++];
		else
			buffer[k++] = array[j++];
	}

	while (i < middle)
		buffer[k++] = array[i++];

	while (j < right)
		buffer[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_recursive - Recursively splits and sorts an array
 * @array: Array to sort
 * @buffer: Temporary buffer
 * @left: Start index
 * @right: End index
 */
void merge_recursive(int *array, int *buffer, size_t left, size_t right)
{
	size_t middle;

	if (right - left < 2)
		return;

	middle = left + (right - left) / 2;

	merge_recursive(array, buffer, left, middle);
	merge_recursive(array, buffer, middle, right);
	merge(array, buffer, left, middle, right);
}

/**
 * merge_sort - Sorts an array using the merge sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_recursive(array, buffer, 0, size);
	free(buffer);
}
