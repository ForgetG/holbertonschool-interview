#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node containing value, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *left, *right, *current;

	if (list == NULL)
		return (NULL);

	left = list;
	right = list->express;

	while (right != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       right->index, right->n);

		if (right->n >= value)
			break;

		left = right;
		right = right->express;
	}

	if (right == NULL)
	{
		right = left;
		while (right->next != NULL)
			right = right->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       left->index, right->index);

	current = left;
	while (current != NULL && current->index <= right->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       current->index, current->n);

		if (current->n == value)
			return (current);

		current = current->next;
	}

	return (NULL);
}
