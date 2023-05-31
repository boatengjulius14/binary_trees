#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of a tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_level = 0, right_level = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_level = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_level = 1 + binary_tree_height(tree->right);

	return (right_level > left_level ? right_level : left_level);
}
