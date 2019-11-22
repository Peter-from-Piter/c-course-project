/*
	File: list.h
	Brief: One linked list header
	Author: Peter Strepetov <strepetov.pa@phystech.edu>
	Created on: 17.11.2019
	MIPT 2019
*/
#pragma once

struct LIST_ENTRY
{
	int value;
	struct LIST_ENTRY *next;
};

typedef struct _LIST
{
	struct LIST_ENTRY *first;
} LIST;

LIST *list_new(); //creates new list and returns pointer to the list

void list_delete(LIST *list); //deletes all list

void list_insert(LIST *l, int a); //insert element with value a to the top of the list

void list_remove(LIST *l, int a); //removes elements with value a from the list

void list_print(LIST *l); //prints all elements of the list
