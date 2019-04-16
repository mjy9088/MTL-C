#ifndef __mtl_list_linkedqueue
#define __mtl_list_linkedqueue

#include "../queue.h"

typedef struct _tagMTL_LinkedQueue
{
	void *type;
	size_t length, size;
	void *head, *tail;
} *MTL_LinkedQueue;

MTL_LinkedQueue new_MTL_LinkedQueue(size_t elementSize);
void MTL_LinkedQueue_release(MTL_LinkedQueue self);

size_t MTL_LinkedQueue_length(MTL_LinkedQueue self);
bool MTL_LinkedQueue_enqueue(MTL_LinkedQueue self, void *value);
bool MTL_LinkedQueue_dequeue(MTL_LinkedQueue self, void **value);
bool MTL_LinkedQueue_peek(MTL_LinkedQueue self, void **value);

#endif
