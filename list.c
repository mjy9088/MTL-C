#include "list.h"

typedef struct
{
	int (*length)(MTL_List self);
	void (*set)(MTL_List self, int idx, void *value);
	void *(*get)(MTL_List self, int idx);
} *MTLDEF_List;

int MTL_List_length(MTL_List self)
{
	return ((MTLDEF_List)self->type)->length(self);
}

void MTL_List_set(MTL_List self, int idx, void *value)
{
	((MTLDEF_List)self->type)->set(self, idx, value);
}

void *MTL_List_get(MTL_List self, int idx)
{
	return ((MTLDEF_List)self->type)->get(self, idx);
}

