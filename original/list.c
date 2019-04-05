#include "list.h"

int MTL_List_length(MTL_List self)
{
	return (*(self->type)->length)(self);
}

bool MTL_List_set(MTL_List self, int idx, void *value)
{
	return (*(self->type)->set)(self, idx, value);
}

bool MTL_List_get(MTL_List self, int idx, void **out)
{
	return (*(self->type)->get)(self, idx, out);
}

void MTL_List_release(MTL_List self)
{
	(*(self->type)->release)(self);
}

