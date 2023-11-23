#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack_utils.h"

stack* stack_split_at(stack *s, size_t index) {
    if (s == NULL || index > s->size) {
        return NULL;
    }

    if (index == s->size) {
        // If index is equal to the size of the stack, return a new empty stack
        stack *newStack = (stack*)malloc(sizeof(stack));
        if (newStack == NULL) {
            return NULL; // Memory allocation failed
        }
        newStack->top = NULL;
        newStack->size = 0;
        return newStack;
    }

    // Create a new stack for the elements to be moved
    stack *newStack = (stack*)malloc(sizeof(stack));
    if (newStack == NULL) {
        return NULL; // Memory allocation failed
    }
    newStack->top = NULL;
    newStack->size = s->size - index;

    // Move elements from the original stack to the new stack
    node *current = s->top;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next;
    }

    newStack->top = current->next;
    current->next = NULL;

    return newStack;
}