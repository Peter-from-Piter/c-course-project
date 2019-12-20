/*
 * This file is bst.h
 * Binary Search Tree (BST)
 *
 */

#pragma once

typedef struct _TREE_NODE *PTREE_NODE;

typedef struct _TREE_NODE
{
	int key;
	float value;
	PTREE_NODE left, right;
} TREE_NODE;

PTREE_NODE init_tree(int key, float value);

/*
 * Add new element to the BST
 * Arguments:
 * 	tree - pointer to the tree
 *	key  - value of map key
 *  value - value of tree
 * Returns pointer to the tree (created or existing)
 */
PTREE_NODE add_node(PTREE_NODE tree, int key, float value); // prototype

/*
 *	Delete element from BST with current key
 *	Arguments:
 * 	tree - pointer to the tree
 *	key  - value of map key
 * Returns pointer to the tree (existing branch or NULL)
*/
PTREE_NODE delete_node(PTREE_NODE tree, int key);

void destroy_tree(PTREE_NODE tree); // destroys tree

void wfs(PTREE_NODE tree); //width tree traversal

void dfs(PTREE_NODE tree); //depth tree traversal