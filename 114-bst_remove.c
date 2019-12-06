#include "binary_trees.h"

/**
 * in_order_successor - returns the successor node
 * @root: root node
 * Return: successor
 */
avl_t *in_order_successor(avl_t *root)
{
	avl_t *temp;

	temp = root;
	if (root->left)
		temp = in_order_successor(root->left);

	return (temp);
}
/**
 * no_successor - performes the deletion if there is no successor
 * @root: root node
 * @temp: pointer to the node to be freed
 * Return: pointer to root
 */
bst_t *no_successor(bst_t *root, bst_t *temp)
{
	if (!temp->parent)
		root = NULL;
	else if (temp->n > temp->parent->n)
		temp->parent->right = NULL;
	else
		temp->parent->left = NULL;
	free(temp);
	return (root);
}
/**
 * successor_new_childs - sets the new childs for the successor
 * @successor: successor node
 * @temp: node to be deleted
 * Return: void
 */
void successor_new_childs(bst_t *successor, bst_t *temp)
{
	if (temp->left != successor)
	{
		successor->left = temp->left;
		if (successor->left)
			successor->left->parent = successor;
	}
	if (temp->right != successor)
	{
		successor->right = temp->right;
		if (successor->right)
			successor->right->parent = successor;
	}
}
/**
 * successor_parent - sets the correct child to the successor parent
 * @successor: node
 * Return: void
 */
void successor_parent(bst_t *successor)
{
	if (successor->parent->n > successor->n)
		successor->parent->left = successor;
	else
		successor->parent->right = successor;
}
/**
 * bst_remove - Search a value in a binary tree.
 *
 * @root: of a subtree.
 * @value: value to search.
 * Return: The root of the tree.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	avl_t *successor = NULL, *temp;

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
	if (temp->right)
		successor = in_order_successor(temp->right);
	else if (temp->left)
		successor = temp->left;
	if (!successor)
		return (no_successor(root, temp));
	if ((successor->right && temp->right) && successor != temp->right)
	{
		successor->right->parent = successor->parent;
		if (successor->right->parent->n > successor->right->n)
			successor->right->parent->left = successor->right;
		else
			successor->right->parent->right = successor->right;
	}
	else if (!successor->right && successor->parent != temp)
		successor->parent->left = NULL;
	successor->parent = temp->parent;
	if (successor->parent)
		successor_parent(successor);
	else
		root = successor;
	successor_new_childs(successor, temp), free(temp);
	return (root);
}
