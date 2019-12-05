#include "binary_trees.h"

/**
 * rotation_right - rotates to the right using previous function
 * @last: pointer to the parent of the node to be rotated
 * Return: pointer to the root of the new subtree
 */
avl_t *rotation_right(avl_t *last)
{
	avl_t *current;

	current = last->right;
	current->parent = NULL;
	current = binary_tree_rotate_right(current);
	current->parent = last;
	last->right = current;
	current->right->parent = current;

	return (current);
}
/**
 * rotation_left - rotates to the left using previous function
 * @last: pointer to the parent of the node to be rotated
 * Return: pointer to the root of the new subtree
 */
avl_t *rotation_left(avl_t *last)
{
	avl_t *current;

	current = last->left;
	current->parent = NULL;
	current = binary_tree_rotate_left(current);
	current->parent = last;
	last->left = current;
	current->left->parent = current;

	return (current);
}
/**
 * avl_insert - inserts a node inside a AVL BST mantaining the structure
 *
 * @tree: double pointer to the root of the tree
 * @value: to be inserted in the new node
 * Return: pinter to the new node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *last, *new_node;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	last = *tree;
	while (last)
	{
		if (last->n < value && last->right)
			last = last->right;
		else if (last->n > value && last->left)
			last = last->left;
		else if (last->n == value)
			return (NULL);
		break;
	}
	if (value > last->n)
		last->right = binary_tree_node(last, value), new_node = last->right;
	else if (value < last->n)
		last->left = binary_tree_node(last, value), new_node = last->left;
	while (last)
	{
		if (binary_tree_balance(last) == 2)
		{
			if (last->left->right)
				rotation_left(last);
			rotation_right(last->parent);
		}
		else if (binary_tree_balance(last) == -2)
		{
			if (last->right->left)
				rotation_right(last);
			rotation_left(last->parent);
		}
		else
			last = last->parent;
	}
	return (new_node);
}
