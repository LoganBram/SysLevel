#include <stdlib.h>
#include <stdio.h>
#include "arr.h"

void main(){
    FILE *file;
    int count = 4;
    char array[10];

    file = fopen("enc01.txt", "r");

    bool x = arr_readline(file, count, array);
    printf("%s\n", array);
    printf("%d", x);
    fclose(file);
}
