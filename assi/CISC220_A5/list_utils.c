#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

bool list_insert_all(list *dest, size_t index, const list *src) {
    // null point
    if (src == NULL || dest == NULL) {
        return false;
    }


    if (index > dest->size) {
        return false;
    }

    // Check if src and dest point to the same list
    if (src->arr == dest->arr) {
        return false;
    }

    

    // Calculate new size after insertion
    size_t new_size = dest->size + src->size;

    // Check if dest has enough capacity, realloc if necessary
    if (dest->capacity < new_size) {
        // Attempt to double the capacity
        size_t new_capacity = (dest->capacity == 0) ? 1 : dest->capacity * 2;
        while (new_capacity < new_size) {
            new_capacity *= 2;
        }

        int *tmp = realloc(dest->arr, new_capacity * sizeof(int));
        if (tmp == NULL) {
            // Memory reallocation failed
            return false;
        }

        dest->arr = tmp;
        dest->capacity = new_capacity;
    }

    // Shift elements to make space for src elements
    memmove(dest->arr + index + src->size, dest->arr + index, (dest->size - index) * sizeof(int));

    // Copy elements from src to dest
    memcpy(dest->arr + index, src->arr, src->size * sizeof(int));

    // Update size of dest
    dest->size = new_size;


    return true;
}
