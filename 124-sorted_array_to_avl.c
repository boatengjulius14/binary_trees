#include "binary_trees.h"
/**
 * create_balanced_avl - builds a balanced AVL tree
 * @parent: pointer to root
 * @array: pointer to array
 * @start: starting index of array
 * @end: ending index of array
 * Return: pointer to new tree or NULL
 */
avl_t *create_balanced_avl(avl_t *parent, int *array, int start, int end)
{
	binary_tree_t *new_tree;
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	new_tree = binary_tree_node((binary_tree_t *)parent, array[mid]);
	if (new_tree == NULL)
		return (NULL);

	root = (avl_t *)new_tree;
	root->left = create_balanced_avl(root, array, start, mid - 1);
	root->right = create_balanced_avl(root, array, mid + 1, end);

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL
 * on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (create_balanced_avl(NULL, array, 0, --size));
}
