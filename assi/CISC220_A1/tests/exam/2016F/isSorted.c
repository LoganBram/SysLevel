#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    if (!f) {
        fprintf(stderr, "Cannot read %s\n", argv[1]);
        exit(1);
    }
    char prev[101];
    char curr[101];
    fgets(prev, 101, f);
    size_t len = strlen(prev);
    if (prev[len - 1] != '\n') {
        fprintf(stderr, "More than 100 characters in line");
        exit(2);
    }
    // remove '\n'
    prev[len - 1] = '\0';
    while (fgets(curr, 101, f)) {
        len = strlen(curr);
        if (curr[len - 1] != '\n') {
            fprintf(stderr, "More than 100 characters in line");
            exit(2);
        }
        // remove '\n'
        curr[len - 1] = '\0';
        if (strcmp(curr, prev) < 0) {
            fprintf(stdout, "lines out of order:\n  %s\n  %s\n", prev, curr);
            exit(3);
        }
        strcpy(prev, curr);
    }
    puts("lines in input are in order");

    fclose(f);
}