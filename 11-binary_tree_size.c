#include "binary_trees.h"

/**
 * size_recursion - function that calculates the size using recursion
 *
 * @tree: node to find size of
 * @left_count: counts the size to the left
 * @right_count: counts the size to the right
 * Return: the number of nodes
 */

size_t size_recursion(const binary_tree_t *tree, size_t left_count, size_t
right_count)
{
	if (tree->left)
		left_count += size_recursion(tree->left, left_count, right_count);
	if (tree->right)
		right_count += size_recursion(tree->right, left_count, right_count);
	return (left_count + right_count + 1);
}

/**
 * binary_tree_size - returns the size of a tree
 * @tree: is the node from which to get the size
 * Return: an integer with the size or 0 if node is null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree)
	{
		if (tree->left)
			left += size_recursion(tree->left, 0, 0);
		if (tree->right)
			right += size_recursion(tree->right, 0, 0);
		return (left + right + 1);
	}
	else
		return (0);
}
