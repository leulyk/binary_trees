#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_leaves - Function counts leaves of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to count the number of leaves.
 *
 * Description: Check existance of leaves in both right and left sub-trees of
 * @tree.
 *
 * Return: Number of leaves of @tree, 1 if no leaves exist.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_leaves(tree->left) +
			binary_tree_leaves(tree->right));
}
