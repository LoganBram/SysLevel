// save as cmdline.c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if (argc < 2){
        printf("%d\n", 0);
    }

    if (argc == 2 ){
        char *val = argv[1];
        double median = atof(val);
        printf("%f\n", median);
        return 0;
    } else if (argc == 4){
        for (int i = 0; i < argc; i++) {
        char *str = argv[i];
        double val = atof(str);
        printf("argv[%d] : %f\n", i, val);
        return 0; }
    }
     else {
        exit(1);
    }



    
}