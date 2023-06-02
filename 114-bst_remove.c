#include "binary_trees.h"
/**
 * bst_find_successor - returns successor
 *
 * @node: Pointer to the non-leaf node
 *
 * Return: pointer to successor node
 */
bst_t *bst_find_successor(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left)
		current = current->left;

	return (current);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: pointer to the root node of the tree where you will to remove a node
 * @value: Value to remove from the tree
 *
 * Return: pointer to the new root node of the tree after removing the
 * desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *successor;

	if (root == NULL)
		return (NULL);

	if (value > root->n)
		root->right = bst_remove(root->right, value);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		successor = bst_find_successor(root->right);
		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}
	return (root);
}
