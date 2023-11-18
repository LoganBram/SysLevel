#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list_utils.h"


int main(void) {
    list *dest = list_init_empty();
    list_add(dest, 1);
    list_add(dest, 2);
    list_add(dest, 3);
    list_add(dest, 4);
    list_add(dest, 5);
    list_add(dest, 6);
    list_add(dest, 7);
    

    list_split_at(dest, 4);



    free(dest->arr);  // Free the memory when you're done
    free(dest);  // Free the list structure

    return 0;
}