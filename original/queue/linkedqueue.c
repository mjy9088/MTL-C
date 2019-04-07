#include <stdlib.h>

#include "linkedqueue.h"

struct
{
	void (*release)(MTL_LinkedQueue self);
	int (*length)(MTL_LinkedQueue self);
	bool (*enqueue)(MTL_LinkedQueue self, void *value);
	bool (*dequeue)(MTL_LinkedQueue self, void **value);
	bool (*peek)(MTL_LinkedQueue self, void **value);
} MTLDEF_LinkedQueue;

typedef struct _tagMTL_LinkedQueue_node
{
	struct _tagMTL_LinkedQueue_node *next;
	void *value;
} MTL_LinkedQueue_node, *MTL_LinkedQueue_Node;

MTL_LinkedQueue new_MTL_LinkedQueue()
{
	MTL_LinkedQueue ret = malloc(sizeof(struct _tagMTL_LinkedQueue));
	if(!ret) return NULL;
	ret->type = &MTLDEF_LinkedQueue;
	ret->length = 0;
	ret->tail = ret->head = NULL;
	return ret;
}

void MTL_LinkedQueue_release(MTL_LinkedQueue self)
{
	MTL_LinkedQueue_node *tmp = self->head, *temp;
	while(tmp->next)
	{
		temp = tmp;
		free(tmp);
		tmp = temp->next;
	}
	free(tmp);
}

int MTL_LinkedQueue_length(MTL_LinkedQueue self)
{
	return self->length;
}

bool MTL_LinkedQueue_enqueue(MTL_LinkedQueue self, void *value)
{
	int i;
	MTL_LinkedQueue_Node tmp = self->head;
	if((tmp = tmp->next = malloc(sizeof(MTL_LinkedQueue_node))) == NULL)
	{
		return false;
	}
	tmp->next = NULL;
	tmp->value = value;
	if(self->tail)
	{
		self->tail = ((MTL_LinkedQueue_Node)self->tail)->next = tmp;
	}
	else
	{
		self->head = self->tail = tmp;
	}
	return true;
}

bool MTL_LinkedQueue_dequeue(MTL_LinkedQueue self, void **value)
{
	if(!self->head)
	{
		return false;
	}
	MTL_LinkedQueue_Node tmp = self->head;
	if(!(self->head = tmp->next))
	{
		self->tail = NULL;
	}
	*value = tmp->value;
	free(tmp);
	return true;
}

bool MTL_LinkedQueue_peek(MTL_LinkedQueue self, void **value)
{
	if(!self->head)
	{
		return false;
	}
	*value = ((MTL_LinkedQueue_Node)self->head)->value;
	return true;
}

__attribute__((constructor)) static void init()
{
	MTLDEF_LinkedQueue.release = &MTL_LinkedQueue_release;
	MTLDEF_LinkedQueue.length = &MTL_LinkedQueue_length;
	MTLDEF_LinkedQueue.enqueue = &MTL_LinkedQueue_enqueue;
	MTLDEF_LinkedQueue.dequeue = &MTL_LinkedQueue_dequeue;
	MTLDEF_LinkedQueue.peek = &MTL_LinkedQueue_peek;
}

