#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_size - Counts the number of nodes in a heap
 * @root: Pointer to the root node
 *
 * Return: Number of nodes
 */
static size_t heap_size(const heap_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * get_last_node - Gets the last node in level-order
 * @root: Pointer to the root node
 * @size: Number of nodes in the heap
 *
 * Return: Pointer to the last node
 */
static heap_t *get_last_node(heap_t *root, size_t size)
{
	size_t bit;

	if (root == NULL || size == 0)
		return (NULL);

	bit = 1;
	while (bit <= size)
		bit <<= 1;

	bit >>= 2;

	while (bit > 0)
	{
		if (size & bit)
			root = root->right;
		else
			root = root->left;

		bit >>= 1;
	}

	return (root);
}

/**
 * heapify_down - Restores the Max Binary Heap property
 * @root: Pointer to the node to heapify
 */
static void heapify_down(heap_t *root)
{
	heap_t *largest;
	int tmp;

	while (root != NULL)
	{
		largest = root;

		if (root->left != NULL && root->left->n > largest->n)
			largest = root->left;

		if (root->right != NULL && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		tmp = root->n;
		root->n = largest->n;
		largest->n = tmp;

		root = largest;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	size_t size;
	int value;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	size = heap_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = get_last_node(*root, size);
	(*root)->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);
	heapify_down(*root);

	return (value);
}
