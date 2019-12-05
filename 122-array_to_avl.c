#include "binary_trees.h"

/**
 * array_to_avl - converts an array into an AVL BST
 * @array: pointer to the first element of an array of integers
 * @size: size of the array
 * Return: pointer to the root of the tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *tree = NULL;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		avl_insert(&tree, array[i]);
	}
	return (tree);
}
