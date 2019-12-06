#include "binary_trees.h"

/**
 * height_recursion - function that calculates the height using recursion
 *
 * @tree: node to find recursion
 * Return: the number of height nodes
 */

size_t height_recursion(const binary_tree_t *tree)
{
	size_t left_count = 0, right_count = 0;

	if (tree->left)
		left_count = height_recursion(tree->left);
	if (tree->right)
		right_count = height_recursion(tree->right);
	return ((left_count > right_count) ? left_count + 1 : right_count + 1);
}

/**
 * binary_tree_balance - returns the height of a tree
 * @tree: is the node from which to get the node
 * Return: an integer with the height or 0 if node is null
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree)
	{
		if (tree->left)
			left = height_recursion(tree->left);
		if (tree->right)
			right = height_recursion(tree->right);
		return (left - right);
	}
	else
		return (0);
}

/**
 * binary_tree_is_full - checks if a tree is full.
 *
 * @tree: root node.
 * Return: 1 if full or 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (!binary_tree_is_full(tree->left))
		return (0);
	if (!binary_tree_is_full(tree->right))
		return (0);
	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		return (0);
	return (1);
}


/**

 * binary_tree_is_perfect - Returns if the tree is perfect
 * @tree: is the node from which to get the node
 *
 * Return: 1 if is perfect, 0 if doesn't
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int isperfect_left = 1, isperfect_right = 1;

	if (tree == NULL)
		return (0);
	if (tree->left)
		isperfect_left = binary_tree_is_perfect(tree->left);
	if (tree->right)
		isperfect_right = binary_tree_is_perfect(tree->right);
	if (binary_tree_is_full(tree) && !binary_tree_balance(tree))
		return (isperfect_left * isperfect_right);
	return (0);
}

heap_t *recursion_heap(heap_t **node, int value)
{
	heap_t *new_node_r = NULL, *new_node_l = NULL, *tmp;

	tmp = *node;
	puts("recursion");
	if (tmp->left)
		new_node_l = recursion_heap(&(tmp->left), value);
	if (tmp->right)
		new_node_r = recursion_heap(&(tmp->right), value);
	if (!(tmp->parent))
	{
		tmp->left = binary_tree_node(tmp, value);
		return (tmp->left);
	}
	else if (binary_tree_balance(tmp) == 0 && binary_tree_balance(tmp->parent) == 1)
	{
		tmp->parent->right = binary_tree_node(tmp->parent, value);
		return (tmp->parent->right);
	}
	else if (binary_tree_balance(tmp) == 0 && binary_tree_balance(tmp->parent) == -1)
	{
		tmp->left = binary_tree_node(tmp, value);
		return (tmp->left);
	}
	else if (binary_tree_balance(tmp) == 1 && binary_tree_balance(tmp->parent) == 0)
	{
		tmp->right = binary_tree_node(tmp, value);
		return (tmp->right);
	}
	if (new_node_l)
		return (new_node_l);
	else
		return (new_node_r);
	return (NULL);
}

/**
 * bst_search - Search a value in a binary tree.
 *
 * @tree: root of a subtree.
 * @value: value to search.
 * Return: The node of value found or null.
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tmp;

	if (*root == NULL)
	{
		printf("Entro");
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	tmp = *root;
	if (binary_tree_is_perfect(tmp))
	{
		while (tmp->left)
		{
			tmp = tmp->left;
		}
		tmp->left = binary_tree_node(tmp, value);
		return (tmp->left);
	}
	else
		return (recursion_heap(&tmp, value));
}
