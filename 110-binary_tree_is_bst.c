#include "binary_trees.h"
/**
 * subtree_great - returns 1 if a subtree contains only values less than n
 *
 * @tree: root of a subtree
 * @n: value to check
 * Return: 1 if a subtree contains only lesser values or 0 if not
 */

int subtree_great(const binary_tree_t *tree, int n)
{
	int left_res = 1, right_res = 1;

	if (tree->left)
		left_res = subtree_great(tree->left, n);
	if (tree->right)
		right_res = subtree_great(tree->right, n);

	if (tree->n >= n)
		return (0);

	return (left_res * right_res);
}
/**
 * subtree_less - returns 1 if a subtree contains only values greater than n
 *
 * @tree: root of a subtree
 * @n: value to check
 * Return: 1 if a subtree contains only greater values or 0 if not
 */

int subtree_less(const binary_tree_t *tree, int n)
{
	int left_res = 1, right_res = 1;

	if (tree->left)
		left_res = subtree_less(tree->left, n);
	if (tree->right)
		right_res = subtree_less(tree->right, n);

	if (tree->n <= n)
		return (0);

	return (left_res * right_res);
}
/**
 * binary_tree_is_bst - returns 1 if a tree is a correct Binary search tree
 *
 * @tree: root of the tree
 * Return: 1 if the tree is BTS or 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left_res = 1, right_res = 1;

	if (!tree)
		return (0);

	if (tree->left)
	{
		if (!subtree_great(tree->left, tree->n))
			return (0);
		left_res = binary_tree_is_bst(tree->left);
	}
	else
		return (1);

	if (tree->right)
	{
		if (!subtree_less(tree->right, tree->n))
			return (0);
		right_res = binary_tree_is_bst(tree->right);
	}
	else
		return (1);

	return (left_res * right_res);
}
