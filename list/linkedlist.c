#include <stdlib.h>

#include "linkedlist.h"

struct
{
	int (*length)(MTL_LinkedList self);
	bool (*set)(MTL_LinkedList self, int idx, void *value);
	bool (*get)(MTL_LinkedList self, int idx, void **value);
} MTLDEF_LinkedList;

typedef struct _tagMTL_LinkedList_node
{
	struct _tagMTL_LinkedList_node *next;
	void *value;
} MTL_LinkedList_node, *MTL_LinkedList_Node;

MTL_ArrayList new_MTL_LinkedList()
{
	MTL_LinkedList ret = malloc(sizeof(struct _tagMTL_LinkedList));
	if(!ret) return NULL;
	ret->type = &MTLDEF_LinkedList;
	ret->length = 0;
	ret->head = NULL;
	return ret;
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
	else if(idx < self->length)
	{
		int i;
		MTL_LinkedList_Node tmp = self->head;
		for(i = 0; i < idx; i++)
		{
			tmp = tmp->next;
		}
		tmp.value = value;
	}
	else
	{
		int i;
		MTL_LinkedList_Node tmp = self->head;
		for(i = 1; i < idx; i++)
		{
			tmp = tmp->next;
		}
		if((tmp = tmp.next = malloc(sizeof(MTL_LinkedList_node))) == NULL)
		{
			return false;
		}
		tmp.next = NULL;
		tmp.value = value;
	}
	return true;
}

__attribute__((constructor)) static void init()
{
	MTLDEF_LinkedList.length = &MTL_LinkedList_length;
	MTLDEF_LinkedList.set = &MTL_LinkedList_set;
	MTLDEF_LinkedList.get = &MTL_LinkedList_get;
}

