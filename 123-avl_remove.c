#include "binary_trees.h"
/**
 * find_successor - returns the minimum value a successor
 * can have
 * @node: pointer to node
 * Return: minimum value, or 0 for failure
 */
int find_successor(bst_t *node)
{
	int left_successor;

	if (node == NULL)
		return (0);

	left_successor = find_successor(node->left);
	if (left_successor == 0)
		return (node->n);

	return (left_successor);
}

/**
 * determine_remove_type - removes a node after checking its
 * successors
 * @root: pointer to node
 * Return: value of node, or 0 for failure
 */
int determine_remove_type(bst_t *root)
{
	int value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		value = find_successor(root->right);
		root->n = value;
		return (value);
	}
}

/**
 * bst_remove - removes nodes from a BST tree
 * @root: pointer to the tree root
 * @value: reference value, for removal
 * Return: updated tree after removal or NULL
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
		determine_remove_type(root);
	return (root);
}

/**
 * balance_avl - estimates the balance factor of an AVL tree
 * @tree: pointer to tree
 * Return: the balance factor
 */
void balance_avl(avl_t **tree)
{
	int balance_factor;

	if (!tree || !*tree)
		return;

	if (!(*tree)->left && !(*tree)->right)
		return;

	balance_avl(&(*tree)->left);
	balance_avl(&(*tree)->right);

	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);

	if (balance_factor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing
 * the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value);

	if (root_a == NULL)
	{
		return (NULL);
	}
	balance_avl(&root_a);

	return (root_a);
}
