#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a tree is full.
 *
 * @tree: root node.
 * Return: 1 if full or 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (!binary_tree_is_full(tree->left))
		return (0);
	if (!binary_tree_is_full(tree->right))
		return (0);
	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		return (0);
	return (1);
}


/**
 * binary_tree_inorder - Entry point
 *
 * Return: Always 0 (Success)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	const binary_tree_t *tmp;
	int isfull;

	if (tree == NULL)
		return (0);
	tmp = tree;
	if (tmp)
	{
		if (tmp->left)
			binary_tree_is_perfect(temp->left);
		isfull = binary_tree_is_full(
		if (temp->right)
			binary_tree_is_perfect(temp->right);

}
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *temp;

	if (tree == NULL || func == NULL)
		return;
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
