#include "binary_trees.h"
/**
 * find_max - returns node with max value in tree
 * @heap_node: pointer to the root of the tree
 * Return: node with max value
 */
heap_t *find_max(heap_t *heap_node)
{
	heap_t *current_max, *left_subtree_max, *right_subtree_max;

	if (!heap_node->left)
		return (heap_node);

	left_subtree_max = find_max(heap_node->left);

	if (left_subtree_max->n > heap_node->n)
		current_max = left_subtree_max;
	else
		current_max = heap_node;

	if (heap_node->right)
	{
		right_subtree_max = find_max(heap_node->right);

		if (right_subtree_max->n > current_max->n)
			current_max = right_subtree_max;
		else
			current_max = heap_node;
	}

	return (current_max);
}

/**
 * recurse_extract - extracts the node with he max value
 * @heap_node: pointer to the root of the tree
 */
void recurse_extract(heap_t *heap_node)
{
	heap_t *subtree_max, *right_subtree_max = NULL;

	if (!heap_node->left)
		return;

	subtree_max = find_max(heap_node->left);
	if (heap_node->right)
		right_subtree_max = find_max(heap_node->right);

	if (right_subtree_max && right_subtree_max->n > subtree_max->n)
		subtree_max = right_subtree_max;

	heap_node->n = subtree_max->n;

	if (!subtree_max->left)
	{
		if (subtree_max->parent && subtree_max->parent->left == subtree_max)
			subtree_max->parent->left = NULL;
		if (subtree_max->parent && subtree_max->parent->right == subtree_max)
			subtree_max->parent->right = NULL;

		free(subtree_max);
	}
	else
		recurse_extract(subtree_max);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the roto node of heap
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int extracted_value;

	if (*root == NULL)
		return (0);

	extracted_value = (*root)->n;

	if ((*root)->left == NULL)
	{
		extracted_value = (*root)->n;
		free(*root);
		*root = NULL;
		return (extracted_value);
	}
	recurse_extract(*root);
	return (extracted_value);
}
