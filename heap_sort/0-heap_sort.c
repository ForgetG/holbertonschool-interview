#include "sort.h"

/**
 * swap_ints - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Restores the max heap property
 * @array: Array to sort
 * @size: Total size of the array
 * @root: Root index of the heap
 * @end: Last index of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t child, swap_idx;

	while ((child = (root * 2) + 1) <= end)
	{
		swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;

		if (child + 1 <= end &&
		    array[swap_idx] < array[child + 1])
			swap_idx = child + 1;

		if (swap_idx == root)
			return;

		swap_ints(&array[root], &array[swap_idx]);
		print_array(array, size);
		root = swap_idx;
	}
}

/**
 * heap_sort - Sorts an array of integers using heap sort
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	i = (size - 2) / 2 + 1;
	while (i > 0)
	{
		i--;
		sift_down(array, size, i, size - 1);
	}

	i = size - 1;
	while (i > 0)
	{
		swap_ints(&array[0], &array[i]);
		print_array(array, size);
		i--;
		sift_down(array, size, 0, i);
	}
}
