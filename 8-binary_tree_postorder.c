#include "binary_trees.h"

/**
 * binary_tree_postorder - Insert a new node in the tree.
 *
 * @tree: Root of the tree.
 * @func: function to excecute.
 *
 * Return: Always 0 (Success)
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *tmp;

	if (tree == NULL || func == NULL)
		return;

	tmp = tree;
	if (tmp)
	{
		if (tmp->left)
			binary_tree_postorder(tmp->left, func);
		if (tmp->right)
			binary_tree_postorder(tmp->right, func);
		func(tmp->n);
	}
}
