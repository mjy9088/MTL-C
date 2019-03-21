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

int tmp_length(MTL_ArrayList self)
{
	return self->length;
}

void tmp_set(MTL_ArrayList self, int idx, void *value)
{
	self->data[idx] = value;
}

void *tmp_get(MTL_ArrayList self, int idx)
{
	return self->data[idx];
}

__attribute__((constructor)) static void init()
{
	MTLDEF_ArrayList.length = &tmp_length;
	MTLDEF_ArrayList.set = &tmp_set;
	MTLDEF_ArrayList.get = &tmp_get;
}

