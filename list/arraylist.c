#include <stdlib.h>

#include "arraylist.h"

struct
{
	int (*length)(MTL_ArrayList self);
	void (*set)(MTL_ArrayList self, int idx, void *value);
	void *(*get)(MTL_ArrayList self, int idx);
} MTLDEF_ArrayList;

MTL_ArrayList new_MTL_ArrayList(int length)
{
	MTL_ArrayList ret = malloc(sizeof(struct _tagMTL_ArrayList) + sizeof(void *) * length);
	if(!ret) return NULL;
	ret->type = &MTLDEF_ArrayList;
	ret->length = length;
	return ret;
}

int MTL_ArrayList_length(MTL_ArrayList self)
{
	return self->length;
}

void MTL_ArrayList_set(MTL_ArrayList self, int idx, void *value)
{
	self->data[idx] = value;
}

void *MTL_ArrayList_get(MTL_ArrayList self, int idx)
{
	return self->data[idx];
}

__attribute__((constructor)) static void init()
{
	MTLDEF_ArrayList.length = &MTL_ArrayList_length;
	MTLDEF_ArrayList.set = &MTL_ArrayList_set;
	MTLDEF_ArrayList.get = &MTL_ArrayList_get;
}

