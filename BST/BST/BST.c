/*
 * This file is bst.c
 * Binary Search Tree (BST) imlpementation
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "queue.h"

PTREE_NODE init_tree(int key, float value)
{
	PTREE_NODE tree = malloc(sizeof(TREE_NODE));
	if (NULL == tree)
	{
		printf("No memory\n");
		return NULL;
	}
	tree->key = key;
	tree->value = value;
	tree->left = NULL;
	tree->right = NULL;

	return tree;
}

PTREE_NODE add_node(PTREE_NODE tree, int key, float value)
{
	if (NULL == tree)
	{
		tree = malloc(sizeof(TREE_NODE));
		if (NULL == tree)
		{
			return NULL;
		}
		tree->key = key;
		tree->value = value;
		tree->left = NULL;
		tree->right = NULL;
	}

	else if (tree->key < key)
		tree->right = add_node(tree->right, key, value);
	else if (tree->key > key)
		tree->left = add_node(tree->left, key, value);
	else if (tree->key == key)
		printf("\nThis key is already used: %d, value: %f\n", key, tree->value);

	return tree;
}

PTREE_NODE delete_node(PTREE_NODE tree, int key)
{
	PTREE_NODE *curtree, del;

	curtree = &tree;
	del = tree;

	while(1)
	{
		if (NULL == del) 
		{
			return 0;
		}
		else if (key == del->key)
		{
			break;
		}
		else if (key > del->key)
		{
			curtree = &del->right;
			del = del->right;
		}
		else
		{
			curtree = &del->left;
			del = del->left;
		}
	}

	if (del->right == NULL) *curtree = del->left;
	else
	{
		PTREE_NODE y = del->right;
		if (y->left == NULL)
		{
			y->left = del->left;
			*curtree = y;
		}
		else
		{
			PTREE_NODE x = y->left;
			while (x->left != NULL)
			{
				y = x;
				x = y->left;
			}
			y->left = x->right;
			x->left = del->left;
			x->right = del->right;
			*curtree = x;
		}
	}
	free(del);
	return *curtree;
}

void destroy_tree(PTREE_NODE tree)
{
	if (tree != NULL)
	{
			destroy_tree(tree->left);
			destroy_tree(tree->right);
	}
	PTREE_NODE tmp = tree;
	tree = NULL;
	if (tmp != NULL)
		free(tmp);
}


void wfs(PTREE_NODE tree) 
{
	Q *q = queue_init();
	
	queue_push(q, tree);

	while (q->head != NULL) 
	{
		PTREE_NODE tmp = q->head->tree;
		queue_pop(q);
		printf("(%d, %f) ", tmp->key, tmp->value);
		
		if (tmp->left) 
		{
			queue_push(q, tmp->left);
		}
		
		if (tmp->right) 
		{
			queue_push(q, tmp->right);
		}
	}
	printf("\n");
}

void dfs(PTREE_NODE tree)
{
	if (tree)
	{
		printf("(%d, %f) ", tree->key, tree->value);
		dfs(tree->left);
		dfs(tree->right);
	}
}

/*void print_tree(PTREE_NODE tree)
{
	if (tree)
	{
		printf("(%d, %f) ", tree->key, tree->value);
		print_tree(tree->right);
		print_tree(tree->left);
	}
	else
		printf("NULL\n");
}

int main(void)
{
	PTREE_NODE tree = init_tree(0, 0);

	add_node(tree, 1, 45);
	add_node(tree, 3, 66);
	add_node(tree, 88, 95);
	add_node(tree, -4, 65);
	add_node(tree, -30, 65);
	add_node(tree, -1, 65);
	add_node(tree, 4, 43);
	add_node(tree, 0, 65);
	add_node(tree, 7, 61);
	add_node(tree, 58, 65);
	print_tree(tree);
	delete_node(tree, 4);
	print_tree(tree);
	wfs(tree);
	dfs(tree);
	//destroy_tree(tree);
	destroy_tree(tree);
	if (tree != NULL)
		printf(" N_O ");
	//print_tree(tree);
	return 0;
}*/