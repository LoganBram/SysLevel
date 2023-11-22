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
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 4;
    arr[5] = 5;
    arr[6] = 6;
    arr[7] = 7;
    arr[8] = 8;
    arr[9] = 9;

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
    stack_print(s, print_int);
    stack_split_at(s, 5);

    free(arr);
    stack_free(s, NULL);

    return 0;
}