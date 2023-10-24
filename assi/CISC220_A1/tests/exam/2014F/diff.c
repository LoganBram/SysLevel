#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int prev = 0;
    int num = 1;
    char buf[128];
    printf("enter a number: ");
    fgets(buf, 128, stdin);
    num = atoi(buf);
    while (num != 0) {
        prev = num;
        printf("enter a number: ");
        fgets(buf, 128, stdin);
        num = atoi(buf);
        if (num == 0) {
            break;
        }
        printf("difference = %d\n", num - prev);
    }
}