#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int *myfun() {
    int *n = malloc(MAX * sizeof(int));
    for (int i = 0; i < MAX; i++) {
        n[i] = rand();
    }
    return n;
}

void myfun2(int *a, int *s) {
    *s = 0;
    for (int i = 0; i < MAX; i++) {
        *s += a[i];
    }
}

int main(void) {
    FILE *f = fopen("data", "a+");
    int *a = myfun();
    int s = 0;
    myfun2(a, &s);
    fprintf(f, "%d\n", s);
    free(a);
    fclose(f);
}