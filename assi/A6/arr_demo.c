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
    int remaininglines_arr[1];
    //2
    arr_readn(file,1,remaininglines_arr);

    //3
    char str[10];
    fgets(str,10,file);

    //4
    char s[100];
    arr_readline(file,100,s);
    for(int i = 0; i < 11; i++){
        printf("%c\n", s[i]);

    }


    s[100];
    arr_readline(file,100,s);

    for(int i = 0; i < 8; i++){
        printf("%c\n", s[i]);

    }
    
    
    
    

}    
