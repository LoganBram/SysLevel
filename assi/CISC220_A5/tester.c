#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    size_t capacity;
    size_t size;
} list;

list *list_init_empty(void) {
    list *new_list = malloc(sizeof(list));
    if (new_list != NULL) {
        new_list->arr = NULL;
        new_list->capacity = 0;
        new_list->size = 0;
    }
    return new_list;
}

void list_add(list *t, int elem) {
    // Add element to the list (you need to implement this function)
}

int main(void) {
    list *dest = list_init_empty();
    list_add(dest, -3);
    list_add(dest, -4);
    list_add(dest, -5);

    // Resize the allocated memory for dest->arr
    int *tmp = realloc(dest->arr, 2 * sizeof(int));

    if (tmp != NULL) {
        dest->arr = tmp;  // Update the dest->arr pointer
        dest->capacity = 2;

        printf("%d\n", dest->arr[0]);
        printf("%d\n", dest->arr[1]);
        // printf("%d\n", dest->arr[2]); // Accessing beyond the allocated size is undefined behavior

        free(dest->arr);  // Free the memory when you're done
    } else {
        printf("Memory reallocation failed.\n");
    }

    free(dest);  // Free the list structure

    return 0;
}
