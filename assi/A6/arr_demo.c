#include <stdlib.h>
#include <stdio.h>
#include "arr.h"

int main(int argc, char *argv[]) {
    
    if(argc != 2){
        fprintf(stderr, "Wrong number of inputs");
        exit(1);
    }
    
    printf("%s", argv[1]);

    FILE *file = fopen(argv[1], "r");

    if(!file){
        fprintf(stderr, "cannot open file");
        exit(2);
    }


    //2
    

    


    
}