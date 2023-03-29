#include "binary_trees.h"

/**
 * bst_helper - check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @low: lowest value that the current node must have
 * @high: highest value that the current node must have
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int bst_helper(const binary_tree_t *tree, int low, int high)
{
	if (tree == NULL)
		return (1);

	if (tree->n < low || tree->n > high)
		return (0);

	return (bst_helper(tree->left, low, tree->n - 1) &&
			bst_helper(tree->right, tree->n + 1, high));
}
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst_helper(tree, INT_MIN, INT_MAX));
}
