#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_postorder - Function calls @func for each traversal.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Description: @func will be called at each traversal and will be passed the
 * data section of that node. Function also performs a postorder traversal by
 * visiting data after traversing both right & left recursively.
 *
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	if (tree->left)
		binary_tree_postorder(tree->left, func);
	if (tree->right)
		binary_tree_postorder(tree->right, func);
	func(tree->n);
}
