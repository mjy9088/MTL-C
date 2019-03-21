#ifndef __mtl_list
#define __mtl_list

typedef struct _tagMTL_List
{
	void *type;
} *MTL_List;

int MTL_List_length(MTL_List self);
void MTL_List_set(MTL_List self, int idx, void *value);
void *MTL_List_get(MTL_List self, int idx);

#endif
