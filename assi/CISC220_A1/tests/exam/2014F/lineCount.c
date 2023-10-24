#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Wrong number of arguments\n");
        exit(1);
    }
    FILE *f = fopen(argv[1], "r");
    if (!f) {
        fprintf(stderr, "Cannot read %s\n", argv[1]);
        exit(2);
    }
    char c;
    size_t n = 0;
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            n++;
        }
    }
    // optional, we did not cover ferror
    if (ferror(f)) {
        fprintf(stderr, "Error while reading %s\n", argv[1]);
        exit(3);
    }
    fclose(f);
    // or n+1 if you want to count the last blank line of the file
    printf("%lu\n", n);
}
