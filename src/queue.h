#pragma once
#include <stddef.h>

#ifndef ITEM
#define ITEM int
#endif

typedef struct queue
{
    ITEM *data;
    size_t head;
    size_t tail;
    size_t size;
    size_t limit;
} queue;

/**
 * queue constructor
 * Note: queue_destroy must be called instead of free
 * */
queue *queue_new();

/**
 * queue destructor
 *   return: zero if OK
 * Note: frees memory
 * */
int queue_destroy(queue *self);

/**
 * add element to the end of the queue
 * */
void queue_push(queue *self, ITEM elem);

/**
 * pop first element from the queue
 * */
ITEM queue_pop(queue *self);

/**
 * check if the queue is empty
 * */
int queue_empty(queue *self);

/**
 * returns the length of the list
 * */
size_t queue_size(queue *self);