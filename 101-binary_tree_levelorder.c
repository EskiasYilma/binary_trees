#include "binary_trees.h"

/**
 * struct queue_s - Queue structure
 * @node: binary tree node
 * @next: pointer to the next queue node
 */
typedef struct queue_s
{
	const binary_tree_t *node;
	struct queue_s *next;
} queue_t;

/**
 * enq - adds a binary tree node to the queue
 * @node: binary tree node to enqueue
 * @queue: pointer to the queue head
 * Return: pointer to the new queue node, or NULL
 */
static queue_t *enq(const binary_tree_t *node, queue_t **queue)
{
	queue_t *new = malloc(sizeof(*new));
	queue_t *tmp;

	if (!new)
		return (NULL);
	new->node = node;
	new->next = NULL;
	if (*queue == NULL)
		*queue = new;
	else
	{
		tmp = *queue;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

/**
 * deq - dequeues a binary tree node from the queue
 * @queue: pointer to the queue head
 * Return: pointer to the dequeued binary tree node, or NULL
 */
static const binary_tree_t *deq(queue_t **queue)
{
	const binary_tree_t *node = NULL;
	queue_t *tmp = NULL;

	if (*queue != NULL)
	{
		node = (*queue)->node;
		tmp = *queue;
		*queue = (*queue)->next;
		free(tmp);
	}
	return (node);
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * Return: Nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;
	const binary_tree_t *node;

	if (tree == NULL || func == NULL)
		return;
	enq(tree, &queue);
	while (queue != NULL)
	{
		node = deq(&queue);
		func(node->n);
		if (node->left != NULL)
			enq(node->left, &queue);
		if (node->right != NULL)
			enq(node->right, &queue);
	}
}
