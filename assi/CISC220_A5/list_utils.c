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

    list_print(dest);



    return true;
}


list *list_split_at(list *t, size_t index){

    //create new list
    list *new = list_init_empty();
    //check if capacity of new list is big enough
    while(new->capacity < index + 1){
        add_capacity(new);
    }
    printf("%zu\n", t->size);
    int j = 1;
    //for loop through list structure one add to list structure 2
    for (int i = 1; i < t->size - index; i++ ){
        new->arr[i-1] = t->arr[index + i];
    }
    new->size = t->size - (index + 1);
    t->size = index+1;
    
    
    for (size_t i = 0; i < t->size; ++i) {
        printf("%d\n", t->arr[i]);
    }
    for (size_t i = 0; i < new->size; ++i) {
         printf("new %d\n", new->arr[i]);
    }

    //realloc memory

    //increase/decrease size
}