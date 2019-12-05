#include "binary_trees.h"

/**
 * subtree - returns 1 if a subtree contains only values less than n
 *
 * @tree: root of a subtree
 * @n: value to check
 * @flag: 1 if left or 0 if right
 * Return: 1 if a subtree contains only lesser values or 0 if not
 */

int subtree(const binary_tree_t *tree, int n, int flag)
{
	int left_res = 1, right_res = 1;

	if (tree->left)
		left_res = subtree(tree->left, n, flag);
	if (tree->right)
		right_res = subtree(tree->right, n, flag);

	if (flag && tree->n >= n)
		return (0);
	else if (!flag && tree->n <= n)
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
		if (!subtree(tree->left, tree->n, 1))
			return (0);
		left_res = binary_tree_is_bst(tree->left);
	}
	else
		return (1);

	if (tree->right)
	{
		if (!subtree(tree->right, tree->n, 0))
			return (0);
		right_res = binary_tree_is_bst(tree->right);
	}
	else
		return (1);

	return (left_res * right_res);
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
 * binary_tree_balance - returns the height of a tree
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
 * binary_tree_is_avl - returns 1 if a tree is a AVL Binary search tree
 *
 * @tree: root of the tree
 * Return: 1 if the tree is AVL or 0 if not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_res = 1, right_res = 1;

	if (!tree)
		return (0);

	if ((binary_tree_balance(tree) != 1 && binary_tree_balance(tree) != 0 &&
	binary_tree_balance(tree) != -1) || !binary_tree_is_bst(tree))
		return (0);
	if (tree->left)
		left_res = binary_tree_is_avl(tree->left);
	if (tree->right)
		right_res = binary_tree_is_avl(tree->right);

	return (left_res * right_res);
}
