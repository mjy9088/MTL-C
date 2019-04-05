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

#endif