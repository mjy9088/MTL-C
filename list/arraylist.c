#include "arraylist.h"

struct
{
	int (*length)(MTL_List self);
	void (*set)(MTL_List self, int idx, void *value);
	void *(*get)(MTL_List self, int idx);
} MTLDEF_ArrayList;

__attribute__((constructor)) static void init()
{
	MTLDEF_ArrayList.length = &tmp_length;
	MTLDEF_ArrayList.set = &tmp_set;
	MTLDEF_ArrayList.get = &tmp_get;
}

