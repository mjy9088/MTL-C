#include <stdlib.h>

#include "arraylist.h"

struct
{
	int (*length)(MTL_List self);
	void (*set)(MTL_List self, int idx, void *value);
	void *(*get)(MTL_List self, int idx);
} MTLDEF_ArrayList;

MTL_ArrayList new_MTL_ArrayList(int length)
{
	MTL_ArrayList *ret = malloc(sizeof(struct _tagMTL_ArrayList) + sizeof(void *) * length);
	if(!ret) return NULL;
	ret->type = &MTLDEF_ArrayList;
	ret->length = length;
	return ret;
}

__attribute__((constructor)) static void init()
{
	MTLDEF_ArrayList.length = &tmp_length;
	MTLDEF_ArrayList.set = &tmp_set;
	MTLDEF_ArrayList.get = &tmp_get;
}

