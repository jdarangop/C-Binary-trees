#include "binary_trees.h"

/**
 * binary_tree_uncle - returns a pointer to the uncle of a node.
 *
 * @node: node.
 * Return: pointer to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *temp;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	temp = node->parent;

	return (temp->parent->left == temp ? temp->parent->right :
temp->parent->left);
}
