#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a new node in the tree.
 *
 * @parent: Parent node.
 * @value: Value of the node.
 *
 * Return: Always 0 (Success)
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *tmp;

	if (parent == NULL)
		return (NULL);

	if (parent->right == NULL)
	{
		new_node = binary_tree_node(parent, value);
		parent->right = new_node;
		return (new_node);
	}
	else
	{
		tmp = parent->right;
		new_node = binary_tree_node(parent, value);
		tmp->parent = new_node;
		new_node->right = tmp;
		parent->right = new_node;
		return (new_node);
	}
}
