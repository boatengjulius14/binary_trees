#include "binary_trees.h"
/**
 * create_node - creates a queue node
 *
 * @node: pointer to address to store in newly created queue node
 *
 * Return: queue node or NULL
*/
queue *create_node(binary_tree_t *node)
{
	queue *newnode;

	newnode = malloc(sizeof(queue));
	if (!newnode)
		return (NULL);
	newnode->node = node;
	newnode->next = NULL;

	return (newnode);
}


/**
 * add_queue - add node to link list queue
 *
 * @node: node to add to queue
 * @tail: pointer to last element of the queue
*/
void add_queue(binary_tree_t *node, queue **tail)
{
	queue *newnode;

	if (node->left != NULL)
	{
		newnode = create_node(node->left);
		(*tail)->next = newnode;
		*tail = newnode;
	}
	if (node->right != NULL)
	{
		newnode = create_node(node->right);
		(*tail)->next = newnode;
		*tail = newnode;
	}
}


/**
 * free_queue - frees queue
 *
 * @head: pointer to head
*/
void free_queue(queue *head)
{
	queue *temp;

	while (temp != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}


/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to the function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue *head, *tail, *temp;

	if (tree == NULL || func == NULL)
		return;

	head = create_node((binary_tree_t *)tree);
	tail = head;

	while (head != NULL)
	{
		func(head->node->n);
		add_queue(head->node, &tail);

		temp = (head)->next;
		free(head);
		head = temp;
	}
}
