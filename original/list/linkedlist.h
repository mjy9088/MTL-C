#ifndef __mtl_list_linkedlist
#define __mtl_list_linkedlist

#include "../list.h"

typedef struct _tagMTL_LinkedList
{
	void *type;
	int length;
	void *head;
} *MTL_LinkedList;

MTL_LinkedList new_MTL_LinkedList();
void MTL_LinkedList_release(MTL_LinkedList self)

int MTL_LinkedList_length(MTL_LinkedList self)
bool MTL_LinkedList_set(MTL_LinkedList self, int idx, void *value)
bool MTL_LinkedList_get(MTL_LinkedList self, int idx, void **value)

#endif
