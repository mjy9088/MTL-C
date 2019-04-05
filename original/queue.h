#ifndef __mtl_queue
#define __mtl_queue

#include "common.h"

typedef struct _tagMTLDEF_Queue *MTLDEF_Queue;

typedef struct _tagMTL_Queue
{
	MTLDEF_Queue type;
} *MTL_Queue;

struct _tagMTLDEF_Queue
{
	void (*release)(MTL_Queue self);
	int (*length)(MTL_Queue self);
	bool (*enqueue)(MTL_Queue self, void *value);
	bool (*dequeue)(MTL_Queue self, void **value);
	bool (*peek)(MTL_Queue self, void **value);
};

int MTL_Queue_length(MTL_Queue self);
bool MTL_Queue_enqueue(MTL_Queue self, void *value);
bool MTL_Queue_dequeue(MTL_Queue self, void **value);
bool MTL_Queue_peek(MTL_Queue self, void **value);
void MTL_Queue_release(MTL_Queue self);

#endif
