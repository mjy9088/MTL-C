#include <stdlib.h>

#include "linkedlist.h"

struct
{
	int (*length)(MTL_LinkedList self);
	void (*set)(MTL_LinkedList self, int idx, void *value);
	void *(*get)(MTL_LinkedList self, int idx);
} MTLDEF_LinkedList;

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

__attribute__((constructor)) static void init()
{
	MTLDEF_ArrayList.length = &MTL_ArrayList_length;
	MTLDEF_ArrayList.set = &MTL_ArrayList_set;
	MTLDEF_ArrayList.get = &MTL_ArrayList_get;
}

