#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Insert a new node in the tree.
 *
 * @node: Parent node.
 *
 * Return: Always 0 (Success)
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL  && node->right == NULL)
		return (1);
	else
		return (0);
}
