#include "stack.h"

#include <stdlib.h>

stack *stack_new()
{
    stack *self = malloc(sizeof(stack));
    self->data = malloc(sizeof(ITEM));
    self->limit = 1;
    self->tail = 0;
}

void stack_push(stack *self, ITEM elem)
{
    if (stack_empty(self))
        realloc(self->data, self->limit << 1);

    self->data[self->tail++] = elem;
}

ITEM stack_pop(stack *self)
{
    return self->data[--self->tail];
}

int stack_empty(stack *self)
{
    return self->tail == self->limit;
}