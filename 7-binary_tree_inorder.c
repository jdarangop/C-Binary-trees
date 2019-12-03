#include "binary_trees.h"

/**
 * binary_tree_inorder - Entry point
 *
 * Return: Always 0 (Success)
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *temp;

	temp = tree;

	if (temp)
	{
		if (temp->left)
			binary_tree_inorder(temp->left, func);
		func(temp->n);
		if (temp->right)
			binary_tree_inorder(temp->right, func);
	}
}