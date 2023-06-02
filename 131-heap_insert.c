#include "binary_trees.h"
/**
 * binary_tree_size - returns the size of a tree
 * @tree: A pointer to the tree
 * Return: tree size, 0 on failure
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left)
	+ binary_tree_size(tree->right) + 1);
}

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *heap, *new_node, *parent;
	int heap_size, remaining_leaves, sub, bit, level, temp;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
		return (*root = binary_tree_node(NULL, value));

	heap = *root;
	heap_size = binary_tree_size(heap);
	remaining_leaves = heap_size;

	for (level = 0, sub = 1; remaining_leaves >= sub; sub *= 2, level++)
		remaining_leaves -= sub;
	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		heap = remaining_leaves & bit ? heap->right : heap->left;

	new_node = binary_tree_node(heap, value);
	remaining_leaves & 1 ? (heap->right = new_node) : (heap->left = new_node);

	parent = new_node;
	for (; parent->parent && (parent->n > parent->parent->n);
					parent = parent->parent)
	{
		temp = parent->n;
		parent->n = parent->parent->n;
		parent->parent->n = temp;
		new_node = new_node->parent;
	}
	return (new_node);
}
