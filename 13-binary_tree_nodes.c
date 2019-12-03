#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the number of nodes (not leaves) in the tree.
 *
 * @tree: root node.
 * Return: the number of nodes that are not leaves
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (!tree)
		return (0);

	counter += binary_tree_nodes(tree->left);
	counter += binary_tree_nodes(tree->right);
	if (!tree->left && !tree->right)
		return (counter);
	return (counter + 1);
}
