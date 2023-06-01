#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 *
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of a node
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	for (; tree->parent; tree = tree->parent)
		depth++;

	return (depth);
}


/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	/*Bring both nodes to the same depth*/
	while (first && second && depth_second != depth_first)
	{
		if (depth_first < depth_second)
		{
			second = second->parent;
			depth_second--;
		}
		else if (depth_first > depth_second)
		{
			first = first->parent;
			depth_first--;
		}
	}
	/*Begin search for first common ancestor if depths are equal*/
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return (NULL);
}
