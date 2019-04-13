#include "list.h"

size_t MTL_List_length(MTL_List self)
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

bool MTL_List_append(MTL_List self, int *idx, void *value)
{
	return (*(self->type)->append)(self, idx, value);
}

bool MTL_List_iterate(MTL_List self, bool (*func)(void *value))
{
	(*(self->type)->iterate)(self, func);
}

void MTL_List_release(MTL_List self)
{
	(*(self->type)->release)(self);
}

