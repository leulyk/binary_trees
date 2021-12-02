#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_uncle - Function finds the uncle/aunt of a node
 *
 * @node : Pointer to the node to find the uncle
 *
 * Description: First goes to the grand parent of current node. Then it returns
 * the other child of that grand parent node.
 *
 * Return: Pointer to uncle/aunt node, NULL if @node is NULL or there is no
 * uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	int i = 2;
	binary_tree_t *current_node = node;

	if (node == NULL)
		return (NULL);
	while (i--)
	{
		if (node->parent)
			node = node->parent;
		else
			return (NULL);
	}

	if (node->left && current_node->parent != node->left)
		return (node->left);
	if (node->right)
		return (node->right);

	return (NULL);
}
