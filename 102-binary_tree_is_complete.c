#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
size_t process_node(const binary_tree_t *node, size_t level, int flag);
size_t binary_tree_levelorder2(const binary_tree_t *tree);
size_t binary_tree_sum(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - check if a binary tree is complete
 *
 * @tree: pointer to the root node
 *
 * Return: 1 if tree is complete, 0 if not or if tree is NULL
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size = 0;

	size = binary_tree_size(tree);

	return (size >= binary_tree_levelorder2(tree));
}

/**
 * binary_tree_levelorder2 - level order traversal of a binary tree
 *
 * @tree: pointer to the root node
 *
 * Description: if @tree or @func is NULL, do nothing
 *
 * Return: total count of nodes discovered
 *
 */
size_t binary_tree_levelorder2(const binary_tree_t *tree)
{
	size_t height, current, total_count = 0;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	for (current = 0; current <= height; ++current)
		total_count += process_node(tree, current, 0);

	return (total_count);
}

/**
 * process_node - execute a function on node
 *
 * @node: the current node to pass to pass to @func
 * @level: level of the node in the binary tree
 * @flag: flag to check in ambiguous cases
 *
 * Return: number of nodes on current level
 *
 */
size_t process_node(const binary_tree_t *node, size_t level, int flag)
{
	size_t count = 0;

	if (!node)
		return (0);
	if (level == 0)
		return (1);
	else if (level > 0)
	{
		if (node->right && !(node->left))
			count += 1;
		if (node->left)
		{
			if (!(node->right) && !flag)
				flag = 1;
			else if (!(node->right) && flag)
				count += 1;
		}
		count += process_node(node->left, level - 1, flag);
		count += process_node(node->right, level - 1, flag);
	}
	return (count);
}

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
