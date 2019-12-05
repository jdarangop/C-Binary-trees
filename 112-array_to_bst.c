#include "binary_trees.h"
/**
 * array_to_bst - Turns an array to a tree.
 *
 * @array: Array to be transformed.
 * @size: Size of the array.
 * Return: The tree of the array.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	for (i = 0; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}
	return (root);
}
