#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a tree is full.
 *
 * @tree: root node.
 * Return: 1 if full or 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (!binary_tree_is_full(tree->left))
		return (0);
	if (!binary_tree_is_full(tree->right))
		return (0);
	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		return (0);
	return (1);
}

/**
 * height_recursion - function that calculates the height using recursion
 *
 * @tree: node to find recursion
 * Return: the number of height nodes
 */

size_t height_recursion(const binary_tree_t *tree)
{
	size_t left_count = 0, right_count = 0;

	if (tree->left)
		left_count = height_recursion(tree->left);
	if (tree->right)
		right_count = height_recursion(tree->right);
	return ((left_count > right_count) ? left_count + 1 : right_count + 1);
}

/**
 * binary_tree_balance - returns the balance of a tree
 * @tree: is the node from which to get the node
 * Return: an integer with the height or 0 if node is null
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree)
	{
		if (tree->left)
			left = height_recursion(tree->left);
		if (tree->right)
			right = height_recursion(tree->right);
		return (left - right);
	}
	else
		return (0);
}
/**
 * binary_tree_is_perfect - Returns if the tree is perfect
 * @tree: is the node from which to get the node
 *
 * Return: 1 if is perfect, 0 if doesn't
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int isperfect_left = 1, isperfect_right = 1;

	if (tree == NULL)
		return (0);
	if (tree->left)
		isperfect_left = binary_tree_is_perfect(tree->left);
	if (tree->right)
		isperfect_right = binary_tree_is_perfect(tree->right);
	if (binary_tree_is_full(tree) && !binary_tree_balance(tree))
		return (isperfect_left * isperfect_right);
	return (0);
}

/**
 * binary_tree_is_complete - returns 1 if the tree is complete
 * @tree: is the node from which to get the tree
 *
 * Return: 1 if is complete, 0 if doesn't
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int complete_left = 1, complete_right = 1;

	if (!tree)
		return (0);
	if (tree->left)
		complete_left = binary_tree_is_complete(tree->left);
	if (tree->right)
		complete_right = binary_tree_is_complete(tree->right);
	if (binary_tree_balance(tree) == 1)
		return (complete_left * complete_right);
	if (!binary_tree_balance(tree))
	{
		if (!tree->right || (tree->left && binary_tree_is_perfect(tree->left)))
			return (complete_left * complete_right);
		else
			return (0);
	}
	return (0);
}
