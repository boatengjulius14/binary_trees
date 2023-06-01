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
 * free_queue - frees queue
 *
 * @head: pointer to head
*/
void free_queue(queue *head)
{
	queue *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
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

	newnode = create_node(node);
	(*tail)->next = newnode;
	*tail = newnode;
}

/**
 * pop_queue - pops node from queue
 * @head: pointer to pointer to head of queue
*/
void pop_queue(queue **head)
{
	queue *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}


/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 if otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue *head, *tail;
	int flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			add_queue(head->node->left, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			add_queue(head->node->right, &tail);
		}
		else
			flag = 1;

		pop_queue(&head);
	}
	return (1);
}
