#include <stdlib.h>

#include "arraylist.h"

struct
{
	void (*release)(MTL_ArrayList self);
	int (*length)(MTL_ArrayList self);
	bool (*set)(MTL_ArrayList self, int idx, void *value);
	bool (*get)(MTL_ArrayList self, int idx, void **value);
} MTLDEF_ArrayList;

MTL_ArrayList new_MTL_ArrayList(int length)
{
	MTL_ArrayList ret = malloc(sizeof(struct _tagMTL_ArrayList) + sizeof(void *) * length);
	if(!ret) return NULL;
	ret->type = &MTLDEF_ArrayList;
	ret->length = length;
	return ret;
}

void MTL_ArrayList_release(MTL_ArrayList self)
{
	free(self->data);
	free(self);
}

int MTL_ArrayList_length(MTL_ArrayList self)
{
	return self->length;
}

bool MTL_ArrayList_set(MTL_ArrayList self, int idx, void *value)
{
	if(self->length > idx)
	{
		self->data[idx] = value;
		return true;
	}
	return false;
}

bool MTL_ArrayList_get(MTL_ArrayList self, int idx, void **value)
{
	if(self->length > idx)
	{
		*value = self->data[idx];
		return true;
	}
	return false;
}

__attribute__((constructor)) static void init()
{
	MTLDEF_ArrayList.release = &MTL_ArrayList_release;
	MTLDEF_ArrayList.length = &MTL_ArrayList_length;
	MTLDEF_ArrayList.set = &MTL_ArrayList_set;
	MTLDEF_ArrayList.get = &MTL_ArrayList_get;
}

