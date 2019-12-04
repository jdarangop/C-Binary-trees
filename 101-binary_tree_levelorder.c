#include "binary_trees.h"

/**
 * depth - returns the depth of a node
 * @node: node to be checked
 * Return: the depth of the node
 */
size_t depth(const binary_tree_t *node)
{
	size_t node_height = 0;
	const binary_tree_t *temp;

	temp = node;
	while (temp->parent)
	{
		temp = temp->parent;
		node_height++;
	}
	return (node_height);
}

/**
 * tree_height - returns the height of a tree
 * @tree: node to the root of the tree
 * Return: height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);
	left = tree_height(tree->left);
	right = tree_height(tree->right);
	if (!tree->left && !tree->right)
		return (0);
	return ((left > right ? left + 1 : right + 1));
}
/**
 * binary_tree_in_order_h - traverses the tree in order; prints in level order
 *
 * @tree: node of the tree
 * @func: function to be called for printing
 * @n_height: level order flag
 * Return: void
 */

void binary_tree_in_order_h(const binary_tree_t *tree, void (*func)(int),
size_t n_height)
{
	if (tree->left)
		binary_tree_in_order_h(tree->left, func, n_height);
	if (depth(tree) == n_height)
		func(tree->n);
	if (tree->right)
		binary_tree_in_order_h(tree->right, func, n_height);
}
/**
 * binary_tree_levelorder - returns a pointer to the uncle of a node.
 *
 * @tree: node.
 * @func: function to be called when printing
 * Return: pointer to the uncle node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height_tree, i;

	if (!tree || !func)
		return;

	height_tree = tree_height(tree);
	for (i = 0; i <= height_tree; i++)
		binary_tree_in_order_h(tree, func, i);
}
