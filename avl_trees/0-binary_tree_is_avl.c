#include "binary_trees.h"
#include <limits.h>

/**
 * avl_check - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root of the tree
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 * @height: Pointer where the subtree height is stored
 *
 * Return: 1 if the tree is AVL, otherwise 0
 */
int avl_check(const binary_tree_t *tree, long min, long max, int *height)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}

	if (tree->n <= min || tree->n >= max)
		return (0);

	if (!avl_check(tree->left, min, tree->n, &left_height))
		return (0);

	if (!avl_check(tree->right, tree->n, max, &right_height))
		return (0);

	if (left_height - right_height > 1 ||
	    right_height - left_height > 1)
		return (0);

	if (left_height > right_height)
		*height = left_height + 1;
	else
		*height = right_height + 1;

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (0);

	return (avl_check(tree, LONG_MIN, LONG_MAX, &height));
}
