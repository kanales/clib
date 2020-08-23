#pragma once

#ifndef ITEM
#define ITEM int
#endif

#include <stddef.h>

typedef struct stack
{
    ITEM *data;
    size_t limit;
    size_t tail;
} stack;

stack *stack_new();
void stack_push(stack *self, ITEM elem);
ITEM stack_pop(stack *self);
int stack_empty(stack *self);