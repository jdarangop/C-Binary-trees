#include "binary_trees.h"
/**
 * bst_search - Search a value in a binary tree.
 *
 * @tree: root of a subtree.
 * @value: value to search.
 * Return: The node of value found or null.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *tmp;

	tmp = tree;
	while (tmp)
	{
		if (tmp->n == value)
			return ((bst_t *)tmp);
		else if (tmp->n > value)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	return (NULL);
}
