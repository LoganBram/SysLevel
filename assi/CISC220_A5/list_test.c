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
    
    list *src = list_init_empty();
    list_add(src, -3);
    list_add(src, -4);
    list_add(src, -5);

    size_t insert = 5;
    bool x = list_insert_all(dest, insert, src); 
    
    list_free(dest);
    list_free(src);
    
}