#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct initials initials;
struct initials {
    char firstChar;
    char lastChar;
};

void firstAndLast(char *filename, initials ini[]) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        fprintf(stderr, "Cannot read %s\n", filename);
        exit(1);
    }
    char buf[51];
    for (int i = 0; i < 5; i++) {
        char *res = fgets(buf, 51, f);
        if (!res) {
            fprintf(stderr, "Cannot read line %d\n", i);
            exit(2);
        }
        // len includes the trailing '\n'; subtract 1 to exclude '\n'
        size_t len = strlen(buf) - 1;
        if (len < 2) {
            fprintf(stderr, "Line %d is too short\n", i);
            exit(3);
        }
        ini[i].firstChar = buf[0];
        ini[i].lastChar = buf[len - 1];
    }
}

int main(int argc, char *argv[]) {
    initials ini[5];
    firstAndLast(argv[1], ini);
    for (int i = 0; i < 5; i++) {
        printf("first : %c, last : %c\n", ini[i].firstChar, ini[i].lastChar);
    }
} 