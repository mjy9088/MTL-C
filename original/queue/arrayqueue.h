#ifndef __mtl_list_arrayqueue
#define __mtl_list_arrayqueue

#include "../queue.h"

typedef struct _tagMTL_ArrayQueue
{
	void *type;
	size_t length, size;
	size_t start;
	size_t capacity;
	void *data;
} *MTL_ArrayQueue;

MTL_ArrayQueue new_MTL_ArrayQueue(int length, size_t elementSize);
void MTL_ArrayQueue_release(MTL_ArrayQueue self);

size_t MTL_ArrayQueue_length(MTL_ArrayQueue self);
bool MTL_ArrayQueue_enqueue(MTL_ArrayQueue self, void *value);
bool MTL_ArrayQueue_dequeue(MTL_ArrayQueue self, void *value);
bool MTL_ArrayQueue_peek(MTL_ArrayQueue self, void *value);

size_t MTL_ArrayQueue_capacity(MTL_ArrayQueue self);

#endif
