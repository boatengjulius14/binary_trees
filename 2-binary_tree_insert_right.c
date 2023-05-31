#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 *
 * @parent: a pointer to the node to insert of the right-child in
 * @value: value to store in the new node
 *
 * Return: a pointer to the created node, or NULL on failure or if
 * parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	if (parent == NULL)
		return (NULL);

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);

	/*Set up and insertion of new node into tree*/
	newnode->parent = parent;
	newnode->n = value;
	newnode->left = NULL;
	newnode->right = parent->right;

	parent->right = newnode;

	if (newnode->right != NULL)
	newnode->right->parent = newnode;
	return (newnode);
}
