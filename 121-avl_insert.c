#include "binary_trees.h"
/**
 * rotation_right - rotates to the right using previous function
 * @last: pointer to the node to be rotated
 * @tree: pointer to the root
 * Return: pointer to the root of the new subtree
 */
avl_t *rotation_right(avl_t **tree, avl_t *last)
{
	avl_t *n_parent;

	if (!last->parent)
	{
		*tree = binary_tree_rotate_right(last);
		return (*tree);
	}

	n_parent = last->parent;
	last->parent = NULL;
	last = binary_tree_rotate_right(last);
	last->parent = n_parent;
	if (last->n < n_parent->n)
		n_parent->left = last;
	else
		n_parent->right = last;

	return (last);
}
/**
 * rotation_left - rotates to the left using previous function
 * @last: pointer to the node to be rotated
 * @tree: root of the tree
 * Return: pointer to the root of the new subtree
 */
avl_t *rotation_left(avl_t **tree, avl_t *last)
{
	avl_t *n_parent;

	if (!last->parent)
	{
		*tree = binary_tree_rotate_left(last);
		return (*tree);
	}

	n_parent = last->parent;
	last->parent = NULL;
	last = binary_tree_rotate_left(last);
	last->parent = n_parent;
	if (last->n < n_parent->n)
		n_parent->left = last;
	else
		n_parent->right = last;

	return (last);
}
/**
 * balance_check - check the balance and calls rotation if necessary
 *
 * @last: pointer to the current node
 * @tree: double pointer to the root node
 * Return: void
 */
void balance_check(avl_t **tree, avl_t *last)
{
	while (last && last->parent)
	{
		if (binary_tree_balance(last) == 1 &&
		binary_tree_balance(last->parent) == 2)
		{
			rotation_right(tree, last->parent);
			break;
		}
		else if (binary_tree_balance(last) == -1 &&
		binary_tree_balance(last->parent) == -2)
		{
			rotation_left(tree, last->parent);
			break;
		}
		else if (binary_tree_balance(last) == -1 &&
		binary_tree_balance(last->parent) == 2)
		{
			last = rotation_left(tree, last);
			rotation_right(tree, last->parent);
			break;
		}
		else if (binary_tree_balance(last) == 1 &&
		binary_tree_balance(last->parent) == -2)
		{
			last = rotation_right(tree, last);
			rotation_left(tree, last->parent);
			break;
		}
		else
			last = last->parent;
	}

}
/**
 * new_root - returns a new root node
 * @tree: double pointer to the tree
 * @value: value to create the node
 * Return: pointer to the new node
 */
avl_t *new_root(avl_t **tree, int value)
{
	*tree = binary_tree_node(NULL, value);
	return (*tree);
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
	avl_t *last, *new_node, *current;

	if (!tree)
		return (NULL);
	if (!*tree)
		return (new_root(tree, value));

	current = *tree;

	while (current)
	{
		last = current;
		if (current->n < value)
			current = current->right;
		else if (current->n > value)
			current = current->left;
		else if (current->n == value)
			return (NULL);
	}

	if (value > last->n)
		last->right = binary_tree_node(last, value), new_node = last->right;
	else if (value < last->n)
		last->left = binary_tree_node(last, value), new_node = last->left;

	balance_check(tree, last);
	return (new_node);
}
