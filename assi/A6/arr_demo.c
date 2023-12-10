#include <stdlib.h>
#include <stdio.h>
#include "arr.h"

int main(int argc, char *argv[]) {
    
    if(argc != 2){
        fprintf(stderr, "Wrong number of inputs\n");
        exit(1);
    }
    
    //printf("%s", argv[1]);

    FILE *file = fopen(argv[1], "r");

    if(!file){
        fprintf(stderr, "cannot open file\n");
        exit(2);
    }
    int remaininglines_arr[1];
    //2
    arr_readn(file,1,remaininglines_arr);

    //3
    char str[10];
    if (fgets(str, 10, file) == NULL) {
        fprintf(stderr, "Error: Failed to read line after number of lines\n");
        fclose(file);
        exit(2);
    }

    //4
    char comparr_string[100];
    size_t arrfromstr_size;
    size_t decompressed_size;    


    

   for(int i = 0; i < remaininglines_arr[0]; i++){
        if(arr_readline(file,100,comparr_string)){
        //printf("%ss\n",comparr);
        //use arr_fromstr
        int *str_to_int_arr = arr_fromstr(comparr_string, &arrfromstr_size);
    

        //decode
        int *decompressed_arr = arr_decode(arrfromstr_size, str_to_int_arr, &decompressed_size);
        for (int i = 0; i < decompressed_size;i++){
            int curr = decompressed_arr[i];
            if (curr == 0){
                printf(" ");
            }
            else{
                printf("#");
            }
            
        }
        printf("\n");

        free(str_to_int_arr);
        free(decompressed_arr);
        }
        else{
            fprintf(stderr, "failed to read line, max length passed or newline not reached");
        }
   }
   fclose(file);
   return 0;

    
        


    


    
    
    
    

}    
