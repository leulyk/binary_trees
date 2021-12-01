#include <stddef.h>
#include "binary_trees.h"

/**
 * binary_trees_ancestor - find the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the ancestor node, or NULL if it can't be found
 *
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	binary_tree_t *t_first, *t_second, *tt_second;

	if (!first || !second)
		return (NULL);

	t_first = (binary_tree_t *)first;
	t_second = (binary_tree_t *)second;
	while (t_first)
	{
		tt_second = t_second;
		while (t_second)
		{
			if (t_first == t_second)
				return (t_first);
			t_second = t_second->parent;
		}
		t_first = t_first->parent;
		t_second = tt_second->parent;
	}

	return (NULL);
}
