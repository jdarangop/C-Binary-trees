#include "binary_trees.h"

avl_t *in_order_successor(avl_t *root)
{
	avl_t *temp;

	temp = root;
	if (root->left)
		temp = in_order_successor(root->left);

	return (temp);
}

/**
 * avl_remove - removes a node in an AVL BST
 * @root: root of the tree
 * @value: value to be deleted
 * Return: pointer to the root
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *successor, *temp;

	temp = root;

	while (temp)
	{
		if (temp->n < value)
			temp = temp->right;
		else if (temp->n > value)
			temp = temp->left;
		else if (temp->n == value)
			break;
	}
	if (!temp)
		return (root);

	if ((temp->left && temp->right) || temp->right)
		successor = in_order_successor(temp->right);
	else if (temp->left)
		successor = temp->left;

	if ((successor->right && temp->right) && successor != temp->right)
	{
		successor->right->parent = successor->parent;
		if (successor->right->parent->n > successor->right->n)
			successor->right->parent->left = successor->right;
		else
			successor->right->parent->right = successor->right;
	}

	successor->parent = temp->parent;
	if (successor->parent)
	{
		if (successor->parent->n > successor->n)
			successor->parent->left = successor;
		else
			successor->parent->right = successor;
	}
	else
		root = successor;

	if (temp->left != successor)
		successor->left = temp->left;
	if (temp->right != successor)
		successor->right = temp->right;

	free(temp);
	return (root);
}
