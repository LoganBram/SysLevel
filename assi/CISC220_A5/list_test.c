#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list_utils.h"


int main(void) {
    list *dest = list_init_empty();
    for (int i = 0; i < 10; ++i) {
        list_add(dest, i);
    }
    
    list *src = list_init_empty();
    list_add(src, -3);
    list_add(src, -4);
    list_add(src, -5);

    size_t insert = 2;
    list_insert_all(dest, insert, src); 
    list_free(dest);
    list_free(src);
    
}