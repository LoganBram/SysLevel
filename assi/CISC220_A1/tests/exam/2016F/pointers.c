#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a = 1;
    int b = 2;
    int c = 3;
    int *p, *q, *r;
    p = &a;
    q = &b;
    r = &a;

    printf("line 1: %d, %d, %d\n", *p, *q, *r);

    p = q;
    q = &c;

    printf("line 2: %d, %d, %d\n", *p, *q, *r);

    *p = *q;
    *r = *q + 1;
    *q = 5;

    printf("line 3: %d, %d, %d\n", *p, *q, *r);
    printf("line 4: %d, %d, %d\n", a, b, c);

    int numbers[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120 };

    printf("line 5: %d, %d\n", *numbers, *(numbers + 2));

    exit(0);
}