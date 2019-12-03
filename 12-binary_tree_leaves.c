#include "binary_trees.h"

/**
 * binary_tree_node - Insert a new node in the tree.
 *
 * @parent: Parent node.
 * @value: Value of the node.
 *
 * Return: Always 0 (Success)
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t counter = 0;
	const binary_tree_t *tmp;


	if (tree == NULL)
		return (0);

	tmp = tree;
	/*if (tmp->left)*/
		counter += binary_tree_leaves(tmp->left);
	/*if (tmp->right)*/
		counter += binary_tree_leaves(tmp->right);
	/*counter++;*/
	if (tmp->left == NULL && tmp->right == NULL)
		return (counter + 1);
	return (counter);
}
