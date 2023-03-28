#include "binary_trees.h"

/**
 * print_level - prints out the values of each node at the given level
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function to call for each node.
 * @level: level of the tree to print
 * Return: Nothing
 */

void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
	{
		return;
	}
	if (level == 1)
	{
		func(tree->n);
	}
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);

	return (1 + (l_height > r_height ? l_height : r_height));
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
	int height, i;

	if (tree == NULL || func == NULL)
	{
		return;
	}
	height = binary_tree_height(tree);
	for (i = 1; i <= height + 1; i++)
	{
		print_level(tree, i, func);
	}
}
