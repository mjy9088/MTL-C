#ifndef __mtl_list_arrayqueue
#define __mtl_list_arrayqueue

#include "../queue.h"

typedef struct _tagMTL_ArrayQueue
{
	void *type;
	int length;
	int capacity;
	void *data[];
} *MTL_ArrayQueue;

MTL_ArrayQueue new_MTL_ArrayQueue(int length);
void MTL_ArrayQueue_release(MTL_ArrayQueue self);

int MTL_ArrayQueue_length(MTL_ArrayQueue self);
bool MTL_ArrayQueue_enqueue(MTL_ArrayQueue self, void *value);
bool MTL_ArrayQueue_dequeue(MTL_ArrayQueue self, void **value);
bool MTL_ArrayQueue_peek(MTL_ArrayQueue self, void **value);

int MTL_ArrayQueue_capacity(MTL_ArrayQueue self);

#endif
