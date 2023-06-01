#include "binary_trees.h"
/**
 * bs_validator - check if tree is a valid Binary Search Tree
 *
 * @tree: pointer to the root node of the tree to check
 * @min: pointer to node with smallest value
 * @max: pointer to node with largest value
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int bst_validator(const binary_tree_t *tree, const binary_tree_t *min,
						const binary_tree_t *max)
{
	if (tree != NULL)
	{
		if ((min && tree->n <= min->n) || (max && tree->n >= max->n))
			return (0);

		return (bst_validator(tree->left, min, tree) &&
			bst_validator(tree->right, tree, max));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst_validator(tree, NULL, NULL));
}
