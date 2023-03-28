#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t *q[100];
	const binary_tree_t *c;
	int front = 0, end = 0, flag = 0;

	if (!tree)
		return (0);
	q[end] = tree;
	end = (end + 1) % 100;
	while (front != end)
	{
		c = q[front];
		front = (front + 1) % 100;
		if (c->left)
		{
			if (flag)
				return (0);
			q[end] = c->left;
			end = (end + 1) % 100;
		}
		else
		{
			flag = 1;
		}
		if (c->right)
		{
			if (flag)
				return (0);
			q[end] = c->right;
			end = (end + 1) % 100;
		}
		else
		{
			flag = 1;
		}
	}
	return (1);
}
