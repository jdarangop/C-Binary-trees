#include "binary_trees.h"

/**
 * rotation_right - rotates to the right using previous function
 * @last: pointer to the parent of the node to be rotated
 * @flag: direction of the child, 1 is right
 * Return: pointer to the root of the new subtree
 */
avl_t *rotation_right(avl_t *last, int flag)
{
	avl_t *current;

	if (flag)
	{
		current = last->right;
		current->parent = NULL;
		current = binary_tree_rotate_right(current);
		current->parent = last;
		last->right = current;
		current->right->parent = current;
	}
	else
	{
		current = last->left;
		current->parent = NULL;
		current = binary_tree_rotate_right(current);
		current->parent = last;
		last->left = current;
		current->right->parent = current;
	}

	return (current);
}
/**
 * rotation_left - rotates to the left using previous function
 * @last: pointer to the parent of the node to be rotated
 * @flag: direction of the child, 1 is right
 * Return: pointer to the root of the new subtree
 */
avl_t *rotation_left(avl_t *last, int flag)
{
	avl_t *current;

	if (!flag)
	{
		current = last->left;
		current->parent = NULL;
		current = binary_tree_rotate_left(current);
		current->parent = last;
		last->left = current;
		current->left->parent = current;
	}
	else
	{
		current = last->right;
		current->parent = NULL;
		current = binary_tree_rotate_left(current);
		current->parent = last;
		last->right = current;
		current->left->parent = current;
	}
	return (current);
}
/**
 * new_root - returns a new root node
 * @tree: double pointer to the tree
 * @value: value to create the node
 * Return: pointer to the new node
 */
avl_t *new_root(avl_t **tree, int value)
{
	*tree = binary_tree_node(*tree, value);
	return (*tree);
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
	while (last)
	{
		if (binary_tree_balance(last) == 2)
		{
			if (last->left->right)
				rotation_left(last, 0);
			if (last->parent)
			{
				if (last->parent->right == last)
					rotation_right(last->parent, 1);
				else
					rotation_right(last->parent, 0);
			}
			else
				*tree = binary_tree_rotate_right(last);
		}
		else if (binary_tree_balance(last) == -2)
		{
			if (last->right->left)
				rotation_right(last, 1);
			if (last->parent)
			{
				if (last->parent->right == last)
					rotation_left(last->parent, 1);
				else
					rotation_left(last->parent, 0);
			}
			else
				*tree = binary_tree_rotate_left(last);
		}
		else
			last = last->parent;
	}
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
