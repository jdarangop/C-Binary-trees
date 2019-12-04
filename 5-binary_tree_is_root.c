#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node in a tree is a root
 * @node: Node.
 *
 * Return: 1 if true or 0 if false
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);
	return (1);
}
