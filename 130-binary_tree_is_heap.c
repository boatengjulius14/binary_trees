#include "binary_trees.h"
/**
 * is_complete - confirms a complete binary tree
 * @tree: pointer to tree
 * @index: current node's index
 * @count: tree count
 * Return: 1 for a complete tree, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int index, int count)
{
	if (tree == NULL)
		return (1);

	if (index >= count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, count) &&
		is_complete(tree->right, 2 * index + 2, count));
}

/**
 * count_nodes - returns the node count of a tree
 * @tree: A pointer to tree
 * Return: number of nodes in the tree
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_max_heap - verifies if a binary tree has max heap property
 * @tree: A pointer to tree
 * Return: 1 if tree has max heap property 0 otherwise
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if ((tree->left != NULL && tree->n < tree->left->n) ||
	    (tree->right != NULL && tree->n < tree->right->n))
		return (0);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}

/**
 * binary_tree_is_heap - checks for a valid Max Binary Heap
 * @tree: A pointer to tree
 * Return: 1 for valid max binary heap tree, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!is_complete(tree, 0, count_nodes(tree)) || !is_max_heap(tree))
		return (0);
	return (1);
}
