#ifndef __mtl_list_arraylist
#define __mtl_list_arraylist

#include "../list.h"

typedef struct _tagMTL_ArrayList
{
	void *type;
	int length;
	void *data[];
} *MTL_ArrayList;

MTL_ArrayList new_MTL_ArrayList(int length);

int MTL_ArrayList_length(MTL_ArrayList self);
void MTL_ArrayList_set(MTL_ArrayList self, int idx, void *value);
void *MTL_ArrayList_get(MTL_ArrayList self, int idx);

#endif
