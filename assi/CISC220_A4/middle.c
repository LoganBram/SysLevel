// save as cmdline.c
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    float float_a = *((float *)a);
    float float_b = *((float *)b);

    if (float_a == float_b) return 0;
    else if (float_a < float_b) return -1;
    else return 1;
}



int main(int argc, char *argv[]) {
    if (argc < 2){
        printf("%f\n", 0.000000);
    }

    if (argc == 2 ){
        char *val = argv[1];
        double median = atof(val);
        printf("%f\n", median);
        return 0;
    } else if (argc == 4){
        float numbers[3];
        for (int i = 1; i < argc; i++) {
            numbers[i-1] = atof(argv[i]);
        }
        qsort(numbers, 3, sizeof(float), compare);
        printf("%f\n", numbers[1]);
    }
     else {
        exit(1);
    }



    
}