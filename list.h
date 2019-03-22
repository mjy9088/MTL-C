#ifndef __mtl_list
#define __mtl_list

#include "common.h"

typedef struct _tagMTL_List
{
	void *type;
} *MTL_List;

int MTL_List_length(MTL_List self);
bool MTL_List_set(MTL_List self, int idx, void *value);
bool MTL_List_get(MTL_List self, int idx, void **value);

#endif
