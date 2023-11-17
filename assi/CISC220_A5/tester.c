#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void main(){
    int *list = malloc(2 * sizeof(int)); // Allocate memory for list dynamically
    
    list[0] = 1;
    list[1] = 2;

    int list2[3] = {10, 20, 30};

    int *tmp = realloc(list, (sizeof(list) + sizeof(list2)) * sizeof(int));

    list = tmp;
    memcpy(list + 1, list2, 3 * sizeof(int));

    printf("%ld\n", sizeof(list[0]));

    for (int i = 0; i < 5; ++i) {
        printf("%d ", tmp[i]);
    }


}