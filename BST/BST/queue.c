#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "bst.h"

Q *queue_init()
{ 
	Q *q = malloc(sizeof(Q));
	if (NULL == q)
	{
		printf("No memory\n");
		return NULL;
	}
	q->head = q->tail = NULL;
	return q;
}

void queue_push(Q *q, PTREE_NODE tree) 
{
	struct LIST_ENTRY *p = (struct LIST_ENTRY*)malloc(sizeof(struct LIST_ENTRY));
	if (p != NULL) 
	{
		p->tree = tree;
		p->next = NULL;
		if (NULL == q->head)
			q->head = q->tail = p;
		else 
		{
			q->tail->next = p;
			q->tail = p;
		}
	}
}

void queue_pop(Q *q) 
{
	struct LIST_ENTRY *del;
	if (q->head != NULL) 
	{
		del= q->head;
		q->head = q->head->next;
		free(del);
		if (q->head == NULL)
			q->tail = NULL;
	}
}

