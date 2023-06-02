#include "binary_trees.h"
/**
 * calculate_tree_height - returns height of a tree
 * @tree: pointer to tree
 * Return: return height, or NULL
 */
size_t calculate_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = 1 + calculate_tree_height(tree->left);
	else
		left_height = 1;

	if (tree->right != NULL)
		right_height = 1 + calculate_tree_height(tree->right);
	else
		right_height = 1;
	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);

	return (0);
}

/**
 * is_avl_helper - check if tree is a valid AVL tree.
 * @tree: pointer to tree
 * @min_value: The value of the smallest node
 * @max_value: The value of the largest node
 * Return: 1 for AVL tree, 0 if otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int min_value, int max_value)
{
	size_t left_height, right_height, height_difference = 0;

	if (tree != NULL)
	{
		if (tree->n < min_value || tree->n > max_value)
			return (0);
		left_height = calculate_tree_height(tree->left);
		right_height = calculate_tree_height(tree->right);
		if (left_height > right_height)
			height_difference = left_height - right_height;
		else
			height_difference = right_height - left_height;
		if (height_difference > 1)
			return (0);
		return (is_avl_helper(tree->left, min_value, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, max_value));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: double pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL tree, 0 if otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, -2147483648, 2147483647));
}
