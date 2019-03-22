#ifndef __mtl_list_arraylist
#define __mtl_list_arraylist

#include "../list.h"

typedef struct _tagMTL_ArrayList
{
	void *type;
	int length;
	void *head;
} *MTL_LinkedList;

MTL_LinkedList new_MTL_LinkedList(int length);

#endif
