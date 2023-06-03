#include "binary_trees.h"
/**
 * tree_height - returns the height of a binary tree
 * @tree: pointer to root node of a tree
 * Return: height of a tree, NULL on failure
 */
size_t tree_height(const heap_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		height_left = 1 + tree_height(tree->left);

	if (tree->right)
		height_right = 1 + tree_height(tree->right);

	if (height_left > height_right)
		return (height_left);
	return (height_right);
}
/**
 * tree_sum - returns height sum
 * @tree: pointer to tree
 * Return: height sum or NULL
 */
size_t tree_sum(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		height_left = 1 + tree_sum(tree->left);

	if (tree->right)
		height_right = 1 + tree_sum(tree->right);

	return (height_left + height_right);
}

/**
 * t_preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traverse
 * @height: height of tree
 *
 * Return: No Return
 */
void t_preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	t_preorder(tree->left, node, height);
	t_preorder(tree->right, node, height);
}

/**
 * heapify - heapifies tree
 * @root: pointer to tree
 */
void heapify(heap_t *root)
{
	int h_value;
	heap_t *temp_1, *temp_2;

	if (root == NULL)
		return;
	temp_1 = root;
	while (1)
	{
		if (temp_1->left == NULL)
			break;
		if (temp_1->right == NULL)
			temp_2 = temp_1->left;
		else
		{
			if (temp_1->left->n > temp_1->right->n)
				temp_2 = temp_1->left;
			else
				temp_2 = temp_1->right;
		}
		if (temp_1->n > temp_2->n)
			break;
		h_value = temp_1->n;
		temp_1->n = temp_2->n;
		temp_2->n = h_value;
		temp_1 = temp_2;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the roto node of heap
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *temp_root, *node;

	if (root == NULL || *root == NULL)
		return (0);

	temp_root = *root;
	extracted_value = temp_root->n;
	if (!temp_root->left && !temp_root->right)
	{
		*root = NULL;
		free(temp_root);
		return (extracted_value);
	}
	t_preorder(temp_root, &node, tree_height(temp_root));
	temp_root->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(temp_root);
	*root = temp_root;

	return (extracted_value);
}
