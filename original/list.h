#ifndef __mtl_list
#define __mtl_list

#include "common.h"

typedef struct _tagMTLDEF_List *MTLDEF_List;

typedef struct _tagMTL_List
{
	MTLDEF_List type;
} *MTL_List;

struct _tagMTLDEF_List
{
	void (*release)(MTL_List self);
	int (*length)(MTL_List self);
	bool (*set)(MTL_List self, int idx, void *value);
	bool (*get)(MTL_List self, int idx, void **value);
	bool (*append)(MTL_List self, int *idx, void *value);
	bool (*iterate)(MTL_List self, bool (*func)(void *value));
};

int MTL_List_length(MTL_List self);
bool MTL_List_set(MTL_List self, int idx, void *value);
bool MTL_List_get(MTL_List self, int idx, void **value);
bool MTL_List_append(MTL_List self, int *idx, void *value);
bool MTL_List_iterate(MTL_List self, bool (*func)(void *value));
void MTL_List_release(MTL_List self);

#endif
