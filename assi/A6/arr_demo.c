#include <stdlib.h>
#include <stdio.h>
#include "arr.h"

int main() {
    const char s[] = "1";
    size_t n;

    int *arr = arr_fromstr(s, &n);
    if (arr != NULL) {
        for (size_t i = 0; i < n; i++) {
            printf("%d\n", arr[i]);
        }
        free(arr); // Free the dynamically allocated array
    }
    printf("count %ld\n", n);

    return 0;
}
