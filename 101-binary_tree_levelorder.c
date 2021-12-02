#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
void process_node(const binary_tree_t *node, void (*func)(int), size_t level);

/**
 * binary_tree_levelorder - level order traversal of a binary tree
 *
 * @tree: pointer to the root node
 * @func: function to call for each node
 *
 * Description: if @tree or @func is NULL, do nothing
 *
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, current;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);
	for (current = 0; current <= height; ++current)
		process_node(tree, func, current);
}

/**
 * process_node - execute a function on node
 *
 * @node: the current node to pass to pass to @func
 * @func: function to call on the node
 * @level: level of the node in the binary tree
 *
 */
void process_node(const binary_tree_t *node, void (*func)(int), size_t level)
{
	if (!node)
		return;
	if (level == 0)
	{
		func(node->n);
	}
	else if (level > 0)
	{
		process_node(node->left, func, level - 1);
		process_node(node->right, func, level - 1);
	}
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
