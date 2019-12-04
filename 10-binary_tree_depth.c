#include "binary_trees.h"

/**
 * binary_tree_depth - Find the depth of the tree.
 *
 * @tree: Root of the tree.
 *
 * Return: Always 0 (Success)
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *current;
	size_t counter = 0;

	if (tree == NULL)
		return (0);
	current = tree;
	while (current->parent != NULL)
	{
		counter++;
		current = current->parent;
	}
	return (counter);
}
