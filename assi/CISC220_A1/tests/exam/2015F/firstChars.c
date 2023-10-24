#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *firstChars(char *holidays[]) {
    // count number of elements
    size_t n = 0;
    while (holidays[n]) {
        n++;
    }
    char *res = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        res[i] = holidays[i][0];
    }
    res[n] = '\0';
    return res;
}

int main(void) {
    char *holidays[] = { "Xmas", "Kwanzaa", "Hanukkah", "NewYears", NULL};
    char *result = firstChars(holidays);
    printf("%s\n", result);
    free(result);
    return 0;
}