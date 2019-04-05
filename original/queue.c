#include "queue.h"

int MTL_Queue_length(MTL_Queue self)
{
	return (*(self->type)->length)(self);
}

bool MTL_Queue_enqueue(MTL_Queue self, void *value)
{
	return (*(self->type)->enqueue)(self, value);
}

bool MTL_Queue_dequeue(MTL_Queue self, void **out)
{
	return (*(self->type)->dequeue)(self, out);
}

bool MTL_Queue_peek(MTL_Queue self, void **out)
{
	return (*(self->type)->peek)(self, out);
}

void MTL_Queue_release(MTL_Queue self)
{
	(*(self->type)->release)(self);
}

