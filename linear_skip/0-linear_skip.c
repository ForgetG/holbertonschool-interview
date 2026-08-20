#include "search.h"

/**
 * search_range - Searches for a value between two indexes
 * @left: First node of the range
 * @right: Last node of the range
 * @value: Value to search for
 *
 * Return: Pointer to the node containing value, or NULL
 */
static skiplist_t *search_range(skiplist_t *left, skiplist_t *right, int value)
{
	skiplist_t *current;

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

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the node containing value, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *left, *right;

	if (list == NULL)
		return (NULL);

	left = list;
	right = list->express;

	while (right != NULL && right->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       right->index, right->n);
		left = right;
		right = right->express;
	}

	if (right != NULL)
		printf("Value checked at index [%lu] = [%d]\n",
		       right->index, right->n);
	else
	{
		right = left;
		while (right->next != NULL)
			right = right->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       left->index, right->index);

	return (search_range(left, right, value));
}
