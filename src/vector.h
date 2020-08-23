#pragma once
#include <stddef.h>

#define ITEM int

typedef struct vector
{
    ITEM *data;
    size_t limit;
    size_t size;
} vector;

/**
 * vector constructor
 * Note: vector_destroy must be called instead of free
 * */
vector *vector_new();

/**
 * vector destructor
 * Note: frees memory
 * */
int vector_destroy(vector *self);

/**
 * Pointer to the beginning of the vector
 * */
ITEM *vector_begin(vector *self);

/**
 * Pointer to the end of the vector
 * */
ITEM *vector_end(vector *self);

/**
 * Appends vector to the end of the vector
 *   updating vector capacity if necessary.
 * */
void vector_push(vector *self, ITEM elem);

/**
 * Returns pointer to the nth element
 * */
ITEM *vector_get(vector *self, size_t n);