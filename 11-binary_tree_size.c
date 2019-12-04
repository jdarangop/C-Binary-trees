#include "binary_trees.h"

/**
 * size_recursion - function that calculates the size using recursion
 *
 * @tree: node to find size of
 * Return: the number of nodes
 */

size_t size_recursion(const binary_tree_t *tree)
{
	size_t left_count = 0, right_count = 0;

	if (tree->left)
		left_count += size_recursion(tree->left);
	if (tree->right)
		right_count += size_recursion(tree->right);
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
			left += size_recursion(tree->left);
		if (tree->right)
			right += size_recursion(tree->right);
		return (left + right + 1);
	}
	else
		return (0);
}
