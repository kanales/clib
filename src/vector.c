#include "vector.h"

#include <stdlib.h>

vector *vector_new()
{
    vector *self = malloc(sizeof(vector));
    self->data = malloc(sizeof(ITEM));
    self->size = 0;
    self->limit = 1;
    return self;
}

int vector_destroy(vector *self)
{
    if (self == NULL || self->data == NULL)
        return 1;
    free(self->data);
    free(self);
    return 0;
}

int *vector_begin(vector *self)
{
    return self->data;
}

int *vector_end(vector *self)
{
    return self->data + self->size;
}

void vector_push(vector *self, ITEM elem)
{
    if (self->size == self->limit)
    {
        self->limit = self->limit << 1;
        self->data = realloc(self->data, sizeof(ITEM) * self->limit);
    }
    self->data[self->size++] = elem;
}

int *vector_get(vector *self, size_t pos)
{
    return self->data + pos;
}