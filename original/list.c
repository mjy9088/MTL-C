#include "list.h"

typedef struct
{
	void (*release)(MTL_List self);
	int (*length)(MTL_List self);
	bool (*set)(MTL_List self, int idx, void *value);
	bool (*get)(MTL_List self, int idx, void **value);
} *MTLDEF_List;

int MTL_List_length(MTL_List self)
{
	return (*((MTLDEF_List)self->type)->length)(self);
}

bool MTL_List_set(MTL_List self, int idx, void *value)
{
	return (*((MTLDEF_List)self->type)->set)(self, idx, value);
}

bool MTL_List_get(MTL_List self, int idx, void **out)
{
	return (*((MTLDEF_List)self->type)->get)(self, idx, out);
}

void MTL_List_release(MTL_List self)
{
	(*((MTLDEF_List)self->type)->release)(self);
}
