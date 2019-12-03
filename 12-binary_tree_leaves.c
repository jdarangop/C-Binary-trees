#include "binary_trees.h"

/**
 * binary_tree_node - Insert a new node in the tree.
 *
 * @parent: Parent node.
 * @value: Value of the node.
 *
 * Return: Always 0 (Success)
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		counter++;
	if (tree->right)
		counter++;
	return (counter);
}
