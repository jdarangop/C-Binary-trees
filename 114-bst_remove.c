#include "binary_trees.h"

bst_t *minimum(bst_t *tree)
{
	while (tree->left)
	{
		tree = tree->left;
	}
	return (tree);
}

/**
 * bst_search - Search a value in a binary tree.
 *
 * @tree: root of a subtree.
 * @value: value to search.
 * Return: The node of value found or null.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *minimo;

	if (root->n == value)
	{
		minimo = minimum(root->right);
		minimo->left = root->left;
		minimo->right = root->right;
		minimo->parent->left = NULL;
		minimo->parent = root->parent;
		/*free(root);*/
		return (minimo);
	}
	tmp = root;
	while (tmp)
	{
		if (tmp->n == value)
		{
			minimo = minimum(tmp->right);
			minimo->left = tmp->left;
			minimo->right = tmp->right;
			minimo->parent->left = NULL;
			minimo->parent = tmp->parent;
			/*free(tmp);*/
		}
		else if (tmp->n > value)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	return (root);
}
