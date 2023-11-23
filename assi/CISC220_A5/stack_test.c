#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack_utils.h"


void print_int(const void *elem) {
    int val = *((int *) elem);
    printf("%d", val);
}

int main(void) {
    stack *s = stack_init_empty();

    int *arr = malloc(10 * sizeof(int));
    arr[0] = 9;
    arr[1] = 8;
    arr[2] = 7;
    arr[3] = 6;
    arr[4] = 5;
    arr[5] = 4;
    arr[6] = 3;
    arr[7] = 2;
    arr[8] = 1;
    arr[9] = 0;

    
    stack_push(s, arr);
    stack_push(s, arr + 1);
    stack_push(s, arr + 2);
    stack_push(s, arr + 3);
    stack_push(s, arr + 4);
    stack_push(s, arr + 5);
    stack_push(s, arr + 6);
    stack_push(s, arr + 7);
    stack_push(s, arr + 8);
    stack_push(s, arr + 9);

    stack *stack = stack_split_at(s, 5);
    stack_print(stack, print_int);
    stack_print(s, print_int);

    free(arr);
    stack_free(s, NULL);

    return 0;
}