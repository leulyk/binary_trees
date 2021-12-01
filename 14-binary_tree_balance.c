#include <stdlib.h>
#include "binary_trees.h"

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
		l_height = binary_tree_balance(tree->left) + 1;
	if (tree->right)
		r_height = binary_tree_balance(tree->right) + 1;

	return (l_height - r_height);
}
