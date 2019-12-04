#include "binary_trees.h"

/**
 * binary_trees_ancestor - returns a pinter to the sibling of a node.
 * @first: First.
 * @second: Second.
 * Return: pointer to the sibling node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const
binary_tree_t *second)
{
	const binary_tree_t *temp1, *temp2;

	temp1 = first;

	while (temp1)
	{
		temp2 = second;
		while (temp2)
		{
			if (temp2 == temp1)
				return ((binary_tree_t *)temp1);
			temp2 = temp2->parent;
		}
		temp1 = temp1->parent;
	}
	return (NULL);
}
