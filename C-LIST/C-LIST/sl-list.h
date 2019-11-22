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

LIST *list_new();

void list_delete(LIST *list);

void list_insert(LIST *l, int a);

void list_remove(LIST *l, int a);

void list_print(LIST *l);
