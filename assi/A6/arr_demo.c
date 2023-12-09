#include <stdlib.h>
#include <stdio.h>
#include "arr.h"

int main() {
    size_t n = 10;
    const int arr[10] = {8,0,2,1,3,9,2,3,4,5};
    size_t dec_len;

    int *myArray = arr_decode(n,arr,&dec_len);

    // Use the array
    for (int i = 0; i < 30; i++) {
        printf("%d ", myArray[i]);
    }


    
}