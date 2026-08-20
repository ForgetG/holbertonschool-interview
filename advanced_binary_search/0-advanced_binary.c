#include "search_algos.h"

/**
 * binary_search - Searches recursively for the first occurrence of a value
 * @array: Pointer to the first element of the current subarray
 * @size: Number of elements in the current subarray
 * @value: Value to search for
 * @offset: Index of the current subarray in the original array
 *
 * Return: Index of the first occurrence of value, or -1
 */
int binary_search(int *array, size_t size, int value, size_t offset)
{
	size_t i, mid;

	if (size == 0)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i + 1 < size)
			printf(", ");
	}
	printf("\n");

	mid = (size - 1) / 2;

	if (array[mid] >= value)
	{
		if (array[mid] == value &&
		    (mid == 0 || array[mid - 1] != value))
			return ((int)(offset + mid));

		return (binary_search(array, mid + 1, value, offset));
	}

	return (binary_search(array + mid + 1, size - mid - 1,
			      value, offset + mid + 1));
}

/**
 * advanced_binary - Searches for the first occurrence of a value
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search(array, size, value, 0));
}
