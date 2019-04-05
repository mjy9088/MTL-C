#include <stdlib.h>

#include "arrayqueue.h"

struct
{
	void (*release)(MTL_ArrayQueue self);
	int (*length)(MTL_ArrayQueue self);
	bool (*enqueue)(MTL_ArrayQueue self, void *value);
	bool (*dequeue)(MTL_ArrayQueue self, void **value);
	bool (*peek)(MTL_ArrayQueue self, void **value);
} MTLDEF_ArrayQueue;

MTL_ArrayQueue new_MTL_ArrayQueue(int length)
{
	MTL_ArrayQueue ret = malloc(sizeof(struct _tagMTL_ArrayQueue) + sizeof(void *) * length);
	if(!ret) return NULL;
	ret->type = &MTLDEF_ArrayQueue;
	ret->capacity = length;
	ret->length = 0;
	return ret;
}

void MTL_ArrayQueue_release(MTL_ArrayQueue self)
{
	free(self->data);
	free(self);
}

int MTL_ArrayQueue_length(MTL_ArrayQueue self)
{
	return self->length;
}

int MTL_ArrayQueue_capacity(MTL_ArrayQueue self)
{
	return self->capacity;
}

__attribute__((constructor)) static void init()
{
	MTLDEF_ArrayQueue.release = &MTL_ArrayQueue_release;
	MTLDEF_ArrayQueue.length = &MTL_ArrayQueue_length;
	MTLDEF_ArrayQueue.enqueue = &MTL_ArrayQueue_enqueue;
	MTLDEF_ArrayQueue.dequeue = &MTL_ArrayQueue_dequeue;
	MTLDEF_ArrayQueue.peek = &MTL_ArrayQueue_peek;
}

