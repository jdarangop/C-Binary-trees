#include "binary_trees.h"

/**
 * binary_tree_insert_left - function that inserts a node to the left
 * child of a tree
 *
 * @parent: Parent node.
 * @value:  value.
 *
 * Return: The node inserted.
 *
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *left_tree;

	if (!parent)
		return (NULL);

	if (!parent->left)
	{
		new_node = binary_tree_node(parent, value);
		parent->left = new_node;
	}
	else
	{
		left_tree = parent->left;
		new_node = binary_tree_node(parent, value);
		parent->left = new_node;
		new_node->left = left_tree;
		left_tree->parent = new_node;
	}

	return (new_node);
}
