#include "binary_trees.h"
/**
 * rotation - rotates to the right or left using previous function
 * @last: pointer to the node to be rotated
 * @tree: pointer to the root
 * @flag_right: if 1 the rotation is to the right else left
 * Return: pointer to the root of the new subtree
 */
avl_t *rotation(avl_t **tree, avl_t *last, int flag_right)
{
	avl_t *n_parent;

	if (flag_right)
	{
		if (!last->parent)
		{
			*tree = binary_tree_rotate_right(last);
			return (*tree);
		}

		n_parent = last->parent;
		last->parent = NULL;
		last = binary_tree_rotate_right(last);
		last->parent = n_parent;
		if (last->n < n_parent->n)
			n_parent->left = last;
		else
			n_parent->right = last;
	}
	else
	{
		if (!last->parent)
		{
			*tree = binary_tree_rotate_left(last);
			return (*tree);
		}

		n_parent = last->parent;
		last->parent = NULL;
		last = binary_tree_rotate_left(last);
		last->parent = n_parent;
		if (last->n < n_parent->n)
			n_parent->left = last;
		else
			n_parent->right = last;
	}
	return (last);
}
/**
 * balance_check_avl - check the balance and calls rotation if necessary
 *
 * @last: pointer to the current node
 * @tree: double pointer to the root node
 * @flag: flag for exiting the balance check
 * Return: void
 */
void balance_check_avl(avl_t **tree, avl_t *last, avl_t *flag)
{
	while (last && last->parent)
	{
		if (binary_tree_balance(last) == 0 && (binary_tree_balance(last->parent)
		== -2 || binary_tree_balance(last->parent) == 2))
		{
			if (last->parent->left && last->parent->left != last)
				last = last->parent->left;
			else if (last->parent->right)
				last = last->parent->right;
			else if (binary_tree_balance(last->parent) == 2)
				flag = rotation(tree, last->parent, 1);
			else
				flag = rotation(tree, last->parent, 0);
		}
		if (flag)
			break;
		if (binary_tree_balance(last) == 1 && binary_tree_balance(last->parent) == 2)
			flag = rotation(tree, last->parent, 1);
		else if (binary_tree_balance(last) == -1 &&
		binary_tree_balance(last->parent) == -2)
			flag = rotation(tree, last->parent, 0);
		else if (binary_tree_balance(last) == -1 &&
		binary_tree_balance(last->parent) == 2)
			last = rotation(tree, last, 0), flag = rotation(tree, last->parent, 1);
		else if (binary_tree_balance(last) == 1 &&
		binary_tree_balance(last->parent) == -2)
			last = rotation(tree, last, 1), flag = rotation(tree, last->parent, 0);
		else if (binary_tree_balance(last) < 2 && binary_tree_balance(last) > -2)
			last = last->parent;
		else
		{
			if (binary_tree_balance(last) > 0)
				last = last->left;
			else
				last = last->right;
		}
		if (flag)
			break;
	}
}

/**
 * in_order_successor - returns the successor node
 * @root: root node
 * @temp: double pointer to the node to be erased
 * @successor: double pointer to the successor node
 * @value: value of the node to be deleted
 * Return: successor
 */
avl_t *in_order_successor(avl_t *root, avl_t **temp, avl_t **successor,
int value)
{
	*temp = root;
	while (*temp)
	{
		if ((*temp)->n < value)
			*temp = (*temp)->right;
		else if ((*temp)->n > value)
			*temp = (*temp)->left;
		else if ((*temp)->n == value)
			break;
	}
	if (!(*temp))
		return (NULL);

	if ((*temp)->right)
	{
		*successor = (*temp)->right;
		while ((*successor)->left)
			*successor = (*successor)->left;
	}
	else if ((*temp)->left)
		*successor = (*temp)->left;

	if (!*successor)
	{
		if (!(*temp)->parent)
			root = NULL;
		else if ((*temp)->n > (*temp)->parent->n)
			(*temp)->parent->right = NULL;
		else
			(*temp)->parent->left = NULL;
		balance_check_avl(&root, (*temp)->parent, NULL);
		free(*temp);
		return (NULL);
	}
	return (*successor);
}
/**
 * successor_new_childs - sets the new childs for the successor
 * @successor: successor node
 * @temp: node to be deleted
 * Return: void
 */
void successor_new_childs(bst_t *successor, bst_t *temp)
{
	if (successor->parent)
	{
		if (successor->parent->n > successor->n)
			successor->parent->left = successor;
		else
			successor->parent->right = successor;
	}
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
 * avl_remove - Searches a value in a AVL binary tree.
 *
 * @root: of a subtree.
 * @value: value to search.
 * Return: The root of the tree.
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *successor = NULL, *temp = NULL, *flag = NULL;

	if (!in_order_successor(root, &temp, &successor, value))
		return (root);

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
	if (!successor->parent)
		root = successor;
	successor_new_childs(successor, temp), free(temp);
	balance_check_avl(&root, successor, flag);
	return (root);
}
