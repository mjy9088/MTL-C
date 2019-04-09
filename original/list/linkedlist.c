#include <stdlib.h>

#include "linkedlist.h"

struct
{
	void (*release)(MTL_LinkedList self);
	int (*length)(MTL_LinkedList self);
	bool (*set)(MTL_LinkedList self, int idx, void *value);
	bool (*get)(MTL_LinkedList self, int idx, void **value);
	bool (*append)(MTL_LinkedList self, int *idx, void *value);
	bool (*iterate)(MTL_LinkedList self, bool (*func)(void *value));
} MTLDEF_LinkedList;

typedef struct _tagMTL_LinkedList_node
{
	struct _tagMTL_LinkedList_node *next;
	void *value;
} MTL_LinkedList_node, *MTL_LinkedList_Node;

MTL_LinkedList new_MTL_LinkedList()
{
	MTL_LinkedList ret = malloc(sizeof(struct _tagMTL_LinkedList));
	if(!ret) return NULL;
	ret->type = &MTLDEF_LinkedList;
	ret->length = 0;
	ret->tail = ret->head = NULL;
	return ret;
}

void MTL_LinkedList_release(MTL_LinkedList self)
{
	MTL_LinkedList_node *tmp = self->head, *temp;
	while(tmp->next)
	{
		temp = tmp;
		free(tmp);
		tmp = temp->next;
	}
	free(tmp);
}

int MTL_LinkedList_length(MTL_LinkedList self)
{
	return self->length;
}

bool MTL_LinkedList_set(MTL_LinkedList self, int idx, void *value)
{
	if(idx > self->length)
	{
		return false;
	}
	else if(idx == self->length)
	{
		return MTL_LinkedList_append(self, NULL, value);
	}
	int i;
	MTL_LinkedList_Node tmp = self->head;
	for(i = 0; i < idx; i++)
	{
		tmp = tmp->next;
	}
	tmp->value = value;
	return true;
}

bool MTL_LinkedList_get(MTL_LinkedList self, int idx, void **value)
{
	if(idx < self->length)
	{
		int i;
		MTL_LinkedList_Node tmp = self->head;
		for(i = 1; i < idx; i++)
		{
			tmp = tmp->next;
		}
		*value = tmp->value;
		return true;
	}
	return false;
}

bool MTL_LinkedList_append(MTL_LinkedList self, int *idx, void *value)
{
	MTL_LinkedList_Node tmp = malloc(sizeof(MTL_LinkedList_node));
	if(tmp == NULL)
	{
		return false;
	}
	tmp->next = NULL;
	tmp->value = value;
	if(self->head)
	{
		self->tail = ((MTL_LinkedList_Node)self->tail)->next = tmp;
	}
	else
	{
		self->head = self->tail = tmp;
	}
	if(idx)
	{
		*idx = self->length;
	}
	self->length++;
	return true;
}

bool MTL_LinkedList_iterate(MTL_LinkedList self, bool (*func)(void *value))
{
	MTL_LinkedList_Node tmp;
	for(tmp = self->head; tmp; tmp = tmp->next)
	{
		if((*func)(tmp->value)) return true;
	}
	return false;
}

__attribute__((constructor)) static void init()
{
	MTLDEF_LinkedList.release = &MTL_LinkedList_release;
	MTLDEF_LinkedList.length = &MTL_LinkedList_length;
	MTLDEF_LinkedList.set = &MTL_LinkedList_set;
	MTLDEF_LinkedList.get = &MTL_LinkedList_get;
}

