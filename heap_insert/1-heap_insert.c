#include <stdlib.h>
#include "binary_trees.h"

/**
 * tree_size - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: Number of nodes in the tree
 */
static size_t tree_size(const heap_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_parent - Finds the parent of the node at a given heap index
 * @root: Pointer to the root of the heap
 * @index: Index of the node to insert
 *
 * Return: Pointer to the parent node
 */
static heap_t *get_parent(heap_t *root, size_t index)
{
	size_t mask;

	mask = 1;
	while (mask <= index)
		mask <<= 1;

	mask >>= 2;

	while (mask > 1)
	{
		if (index & mask)
			root = root->right;
		else
			root = root->left;

		mask >>= 1;
	}

	return (root);
}

/**
 * heapify - Restores the Max Heap property
 * @node: Pointer to the newly inserted node
 *
 * Return: Pointer to the node containing the inserted value
 */
static heap_t *heapify(heap_t *node)
{
	int tmp;

	while (node->parent != NULL && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}

	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the new node
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent;
	heap_t *node;
	size_t index;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	index = tree_size(*root) + 1;
	parent = get_parent(*root, index);

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (index & 1)
		parent->right = node;
	else
		parent->left = node;

	return (heapify(node));
}
