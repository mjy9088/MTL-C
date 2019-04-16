#ifndef __mtl_list_arraylist
#define __mtl_list_arraylist

#include "../list.h"

typedef struct _tagMTL_ArrayList
{
	void *type;
	size_t capacity;
	size_t length;
	size_t size;
	void **data;
} *MTL_ArrayList;

MTL_ArrayList new_MTL_ArrayList(size_t length, size_t elementSize);
void MTL_ArrayList_release(MTL_ArrayList self);

size_t MTL_ArrayList_length(MTL_ArrayList self);
bool MTL_ArrayList_set(MTL_ArrayList self, size_t idx, void *value);
bool MTL_ArrayList_get(MTL_ArrayList self, size_t idx, void *value);
bool MTL_ArrayList_append(MTL_ArrayList self, size_t *idx, void *value);
bool MTL_ArrayList_iterate(MTL_ArrayList self, bool (*func)(void *value));

size_t MTL_ArrayList_capacity(MTL_ArrayList self);

#endif
