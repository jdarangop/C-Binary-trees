#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotate to left a tree.
 *
 * @tree: root node.
 * Return: New root.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	new_root = tree->right;
	tree->parent = new_root;
	tree->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = tree;
	new_root->left = tree;
	new_root->left->parent = new_root;
	new_root->parent = NULL;
	return (new_root);
}
