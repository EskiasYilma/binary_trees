#include "binary_trees.h"

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
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);

	return (l_height - r_height);
}

