#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	 /*
	 * Add +1 afterwards, to differenciate btn passing
	 * NULL and passing a leaf node
	 */
	left = binary_tree_height(tree->left);
	if (tree->left)
		left++;

	right = binary_tree_height(tree->right);
	if (tree->right)
		right++;

	return (left - right);
}
