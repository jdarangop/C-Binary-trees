#include "binary_trees.h"
/**
 * bst_insert - Insert a value with binary searche tree.
 *
 * @tree: root of a subtree.
 * @value: value to insert.
 * Return: The node inserted.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp, *last;

	tmp = *tree;
	while (tmp)
	{
		last = tmp;
		if (tmp->n > value)
			tmp = tmp->left;
		else if (tmp->n < value)
			tmp = tmp->right;
		else
			return (NULL);
	}
	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	else if (last->n > value)
	{
		last->left = binary_tree_node(last, value);
		return (last->left);
	}
	/*else if (last->n < value)*/
	else
	{
		last->right = binary_tree_node(last, value);
		return (last->right);
	}
}
