#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates a tree to the right
 *
 * @tree: pointer to the root
 * Return: pointer to the new root
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (!tree || !tree->left)
		return (NULL);

	temp = tree->left;

	tree->left = temp->right;
	if (tree->left)
		tree->left->parent = tree;

	tree->parent = temp;
	temp->right = tree;

	temp->parent = NULL;

	return (temp);
}
