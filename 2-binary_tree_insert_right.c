#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts node as a right-child to @parent
 *
 * @parent: parent node to inert the right child inert
 * @value: date the new node will store
 *
 * Description: if parent already has a right child, the new node must take its
 * place, and right-child must be set as the right of the new node.
 *
 * Return: the new node, or NULL if failure on malloc or parent is NULL
 *
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *r_child;

	if (parent == NULL)
		return (NULL);
	r_child = malloc(sizeof(binary_tree_t));
	if (r_child == NULL)
		return (NULL);

	r_child->n = value;
	r_child->left = NULL;
	r_child->parent = parent;

	if (parent->right == NULL)
		parent->right = r_child, r_child->right = NULL;
	else
	{
		r_child->right = parent->right;
		parent->right->parent = r_child;
		parent->right = r_child;
	}
	return (r_child);
}
