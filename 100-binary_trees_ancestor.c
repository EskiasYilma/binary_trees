#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: pointer to the lowest common ancestor node of
 * the two given nodes or NULL If no common ancestor was found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	const binary_tree_t *tmp;

	if (!first || !second)
		return (NULL);

	tmp = second;
	while (first)
	{
		while (second)
		{
			if (first == second)
				return ((binary_tree_t *)first);
			second = second->parent;
		}
		second = tmp;
		first = first->parent;
	}
	return (NULL);
}
