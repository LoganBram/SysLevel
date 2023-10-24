#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // question is underspecified
    // -error handling?
    // -overflow?

    puts("Enter a positive integer: ");
    unsigned int n;
    if (scanf("%u", &n) != 1) {
        fprintf(stderr, "Could not convert input to unsigned int\n");
        exit(1);
    }
    unsigned long int fact = 1;
    for (unsigned int i = 2; i <= n; i++) {
        fact *= i;
        if (fact > UINT_MAX) {
            fprintf(stderr, "fact(%u) too large for unsigned int\n", n);
            exit(1);
        }
    }
    printf("fact(%u) = %lu\n", n, fact);
}