#include "binary_trees.h"
/**
 * binary_tree_nodes - function that counts the non-leaf nodes
 *
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: number of non-leaf nodes
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree && (tree->right || tree->left))
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));

	return (0);
}
