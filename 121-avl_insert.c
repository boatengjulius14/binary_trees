#include "binary_trees.h"
/**
 * tree_height - returns the height of a binary tree
 * @tree: pointer to tree
 * Return: height of tree, or NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = 1 + tree_height(tree->left);
	else
		left_height = 1;

	if (tree->right)
		right_height = 1 + tree_height(tree->right);
	else
		right_height = 1;

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

/**
 * tree_balance - estimates the balance factor a binary tree
 * @tree: pointer to tree
 * Return: balance factor of a tree, or NULL
 */
int tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (tree_height(tree->left) - tree_height(tree->right));
}

/**
 * avl_insert_recursive - Adds value to AVL tree
 * @tree: double pointer to AVL tree
 * @parent: pointer to parent of node
 * @new_node: double pointer to reserve node
 * @value: value to insert in tree
 * Return: pointer to root of AVL tree, or NULL
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
				avl_t **new_node, int value)
{
	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent, value));

	(*tree)->n > value ? ((*tree)->left = avl_insert_recursive(&(*tree)->left,
								   *tree, new_node, value))
			   : ((*tree)->n < value ?
			((*tree)->right = avl_insert_recursive(&(*tree)->right,
											  *tree, new_node, value))
						 : (*tree));

	if (tree_balance(*tree) > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (tree_balance(*tree) < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (tree_balance(*tree) > 1 && (*tree)->left->n < value)
		((*tree)->left = binary_tree_rotate_left((*tree)->left)),
			(*tree = binary_tree_rotate_right(*tree));
	else if (tree_balance(*tree) < -1 && (*tree)->right->n > value)
		((*tree)->right = binary_tree_rotate_right((*tree)->right)),
			(*tree = binary_tree_rotate_left(*tree));

	return (*tree);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (!tree)
		return (NULL);

	if (!*tree)
		return (*tree = binary_tree_node(NULL, value));

	avl_insert_recursive(tree, *tree, &new_node, value);
	return (new_node);
}
