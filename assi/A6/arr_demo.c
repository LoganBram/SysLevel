#include <stdlib.h>
#include <stdio.h>
#include "arr.h"

void main(){
    FILE *file;
    int count = 2;
    int array[10];

    file = fopen("enc01.txt", "r");

    arr_readn(file, count, array);
    
    printf("%d\n", array[0]);
    printf("%d", array[1]);



    fclose(file);
}
