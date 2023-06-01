#include "binary_trees.h"
/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (!tree || !tree->right)
		return (NULL);

	root = tree->right;
	tree->right = root->left;

	if (root->left)
		root->left->parent = tree;

	root->left = tree;
	root->parent = tree->parent;
	tree->parent = root;

	return (root);
}
