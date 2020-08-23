#include "queue.h"

#include <stdlib.h>

/**
 * queue constructor
 * Note: queue_destroy must be called instead of free
 * */
queue *queue_new()
{
    queue *self = malloc(sizeof(queue));
    self->data = malloc(sizeof(ITEM));
    self->size = 0;
    self->limit = 1;
    self->head = self->tail = 0;
    return self;
}

/**
 * check if the queue is empty
 * */
int queue_empty(queue *self)
{
    return self->size == 0;
}

size_t queue_size(queue *self)
{
    return self->size;
}

/**
 * queue destructor
 *   return: zero if OK
 * Note: frees memory
 * */
int queue_destroy(queue *self)
{
    if (self == NULL || self->data == NULL)
        return 1;
    free(self->data);
    free(self);
    return 0;
}

void queue_realloc(queue *self, size_t new_limit)
{
    ITEM *newdata = malloc(new_limit * sizeof(ITEM));
    size_t i = 0;
    for (size_t i = 0; i < self->size; i++)
    {
        newdata[i] = self->data[(self->head + i) % self->limit];
    }
    free(self->data);
    self->data = newdata;
    self->head = 0;
    self->tail = self->size;
    self->limit = new_limit;
}

/**
 * add element to the end of the queue
 * */
void queue_push(queue *self, ITEM elem)
{
    if (self->size == self->limit)
    {
        queue_realloc(self, self->size << 1);
    }

    self->data[self->tail] = elem;
    self->tail = (self->tail + 1) % self->limit;
    self->size += 1;
}

/**
 * pop first element from the queue
 * panics if empty
 * */
ITEM queue_pop(queue *self)
{
    if (queue_empty(self))
        exit(1);

    ITEM elem = self->data[self->head];
    self->head = (self->head + 1) % self->limit;
    self->size -= 1;
    return elem;
}