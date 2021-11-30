#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as a left-child of another node
 *
 * @parent: parent node to insert the left child in
 * @value: value to put in the new node
 *
 * Description: if parent already has a left child, the new node must replace
 * the old one, which will be set as a left child to the new one
 *
 * Return: the new node, or NULL if failure or parent is NULL
 *
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *l_child;

	if (!parent)
		return (NULL);
	l_child = binary_tree_node(parent, value);
	if (!l_child)
		return (NULL);

	if (parent->left)
	{
		l_child->left = parent->left;
		parent->left->parent = l_child;
		l_child->parent = parent;
	}
	parent->left = l_child;

	return (l_child);
}
