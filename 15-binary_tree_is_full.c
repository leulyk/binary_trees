#include <stddef.h>
#include "binary_trees.h"

/**
 * binary_tree_is_full - check if a binary tree is full
 *
 * @tree: pointer to the root of the binary tree
 *
 * Return: 1 if full, 0 if not or if tree is NULL
 *
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int l_state = 0, r_state = 0;

	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (1);

	if (tree->left && tree->right)
	{
		l_state = binary_tree_is_full(tree->left);
		r_state = binary_tree_is_full(tree->right);
	}

	return (l_state && r_state);
}
