#include "binary_trees.h"

/**
 * binary_tree_sibling - returns a pinter to the sibling of a node.
 *
 * @node: node.
 * Return: pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *child_r, *child_l;

	if (!node || !node->parent)
		return (NULL);

	child_r = node->parent->right;
	child_l = node->parent->left;
	return (child_r == node ? child_l : child_r);
}
