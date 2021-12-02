#include <stdlib.h>
#include "binary_trees.h"

/**
 * sub_heights_are_equal - Function returns height of passed node.
 *
 * @tree: Pointer to node to be measured.
 *
 * Return: Height of @tree.
 */
size_t sub_heights_are_equal(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = sub_heights_are_equal(tree->left) + 1;
	if (tree->right)
		r_height = sub_heights_are_equal(tree->right) + 1;

	return (l_height > r_height ? l_height : r_height);
}

/**
 * get_nodes_count - Function returns number of nodes.
 *
 * @tree: Pointer to root node of a tree to count its nodes.
 *
 * Return: Nodes count of @tree
 */
size_t get_nodes_count(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (get_nodes_count(tree->left) + get_nodes_count(tree->right) + 1);
}

/**
 * power - Function raises 2 to @n
 * @n: Exponent of power
 *
 * Return: 2 to the power of @node
 */
size_t power(int n)
{
	size_t num = 2;

	while (--n)
		num *= 2;

	return (num);
}
/**
 * binary_tree_is_perfect - Function checkes if tree is perfect.
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = sub_heights_are_equal(tree);

	return (get_nodes_count(tree) == (power(height + 1) - 1) ? 1 : 0);
}
