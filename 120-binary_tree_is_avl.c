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
 * check_bst - Checks if a binary tree is a BST.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a BST, and 0 otherwise.
 */

int check_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);
	if (tree->right != NULL && tree->right->n < tree->n)
		return (0);
	if (!check_bst(tree->left) || !check_bst(tree->right))
		return (0);
	return (1);
}

/**
 * check_bal - Checks if a binary tree is balanced according to
 * AVL Tree properties.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is balanced, and 0 otherwise.
 */

int check_bal(const binary_tree_t *tree)
{
	int diff;

	if (tree == NULL)
		return (1);
	diff = binary_tree_height(tree->left) - binary_tree_height(tree->right);
	if (diff < -1 || diff > 1)
		return (0);
	if (!check_bal(tree->left) || !check_bal(tree->right))
		return (0);
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (!check_bst(tree))
		return (0);
	if (!check_bal(tree))
		return (0);
	return (1);
}

