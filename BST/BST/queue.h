#pragma once
#include "bst.h"
/*
 * This file is queue.h
 * This is realization of queue for wfs function
 *
 */

struct LIST_ENTRY
{
	PTREE_NODE tree;
	struct LIST_ENTRY *next;
};

typedef struct _QUEUE
{
	struct LIST_ENTRY *head;
	struct LIST_ENTRY *tail;
} Q;

Q* queue_init(); //creates new queue and returns pointer to the queue

void queue_push(Q *q, PTREE_NODE tree); //insert element with value & key a to the end of the queue

void queue_pop(Q *q); //removes element from the top of the queue
