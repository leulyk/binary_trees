#include <stddef.h>
#include "binary_trees.h"


/**
 * binary_tree_sum - computes the total nodes under a root node
 *
 * @tree: pointer to the root node
 *
 * Return: total number of nodes
 *
 */
size_t binary_tree_sum(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_height = binary_tree_sum(tree->left) + 1;
	if (tree->right)
		right_height = binary_tree_sum(tree->right) + 1;

	return (left_height + right_height);
}

/**
 * binary_tree_size - compute size of a binary tree
 *
 * @tree: pointer to the root node
 *
 * Return: computed size, or 0 if tree is NULL
 *
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_sum(tree) + 1);
}
