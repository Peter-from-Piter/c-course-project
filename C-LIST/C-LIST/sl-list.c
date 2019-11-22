#include <stdio.h>
#include <stdlib.h>
#include "sl-list.h"

LIST *list_new()
{
	LIST *L = malloc(sizeof(LIST));
	if (NULL == L)
	{
		printf("No memory\n");
		return NULL;
	}
	L->first = NULL;
	return L;
}

void list_delete(LIST *list)
{
	if (NULL != list)
		if (NULL == list->first)
			free(list->first);
		else
		{
			struct LIST_ENTRY *tmp = malloc(sizeof(struct LIST_ENTRY));
			if (NULL == tmp)
			{
				printf("ERROR: not enough memory\n");
				exit(0);
			}
			while (list->first != NULL)
			{
				tmp = list->first;
				list->first = list->first->next;
			}
			list->first = NULL;
			free(list->first);
			free(tmp);
		}
	list = NULL;
	free(list);
}

void list_insert(LIST *l, int a)
{
	struct LIST_ENTRY *new = malloc(sizeof(struct LIST_ENTRY));
	if (NULL == new)
	{
		printf("ERROR: not enough memory\n");
		exit(0);
	}

	new->next = l->first;
	new->value = a;
	l->first = new;
}

void list_remove(LIST *l, int a)
{

	if (l && l->first != NULL)
	{
		struct LIST_ENTRY *tmp = malloc(sizeof(struct LIST_ENTRY));
		struct LIST_ENTRY *current = l->first;
		
		while (l->first && l->first->value == a)
		{
			if (NULL == tmp)
			{
				printf("ERROR: not enough memory\n");
				exit(0);
			}
			tmp = l->first;
			l->first = l->first->next;
			current = current->next;
			tmp->next = NULL;
			free(tmp);
		}
		while (current && current->next != NULL)
		{
			if (current->next->value == a)
			{
				if (NULL == tmp)
				{
					printf("ERROR: not enough memory\n");
					exit(0);
				}
				tmp = current->next;
				current->next = current->next->next;
				tmp->next = NULL;
				free(tmp);
			}
			else
				current = current->next;
		}
	}
}

void list_print(LIST *l)
{
	if (l != NULL && l->first != NULL)
	{
		struct LIST_ENTRY *current = l->first;
		printf("%d\n", current->value);
		while (current->next != NULL)
		{
			printf("%d\n", current->next->value);
			current = current->next;
		}
	}
	else
		printf("Empty list\n");
}