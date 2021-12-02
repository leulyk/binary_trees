#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - computes height of a binary tree
 *
 * @tree: pointer to the root node
 *
 * Return: computed height, 0 if tree is NULL
 *
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_height = binary_tree_height(tree->left) + 1;
	if (tree->right)
		right_height = binary_tree_height(tree->right) + 1;
	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - Function caculates the balance factor of a tree
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Description: Calculates the left and right heights and returns the
 * difference of the two starting with the left side height.
 *
 * Return: Balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int l_height = 0, r_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		l_height = binary_tree_height(tree->left) + 1;
	if (tree->right)
		r_height = binary_tree_height(tree->right) + 1;

	if (!l_height && tree->left)
		l_height = 1;
	if (!r_height && tree->right)
		r_height = 1;

	return (l_height - r_height);
}
