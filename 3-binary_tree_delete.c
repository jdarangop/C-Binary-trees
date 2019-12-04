#include "binary_trees.h"

/**
 * binary_tree_delete - Entry point
 * @tree: Tree root.
 *
 * Return: Always 0 (Success)
 */

void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *temp;

	temp = tree;
	if (temp)
	{
		if (temp->left)
		{
			binary_tree_delete(temp->left);
		}
		if (temp->right)
		{
			binary_tree_delete(temp->right);
		}
		free(temp);
	}
}
