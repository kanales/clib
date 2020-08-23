#include <pthread.h>

#ifndef ITEM
#define ITEM int
#endif

#include "queue.h"

typedef struct
{
    queue q;
    pthread_mutex_t lock;
} squeue;

squeue *squeue_new();
void squeue_destroy(squeue *self);
void squeue_push(squeue *self, ITEM elem);
ITEM squeue_pop(squeue *self);
int squeue_size(squeue *self);
int squeue_empty(squeue *self);