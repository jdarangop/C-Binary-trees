#include "binary_trees.h"

/**
 * binary_tree_node - Insert a new node in the tree.
 *
 * @parent: Parent node.
 * @value: Value of the node.
 *
 * Return: Always 0 (Success)
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *tmp;

	if (tree == NULL || func == NULL)
		return;

	tmp = tree;
	if (tmp)
	{	
		func(tmp->n);
		if (tmp->left)
			binary_tree_preorder(tmp->left, func);
		if (tmp->right)
			binary_tree_preorder(tmp->right, func);
	}
}
