#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stringMerge(const char *s, const char *t) {
    size_t len = strlen(s) + strlen(t) + 1;
    char *res = malloc(len);
    strcpy(res, s);
    strcat(res, t);
    return res;
}

int main(void) {
    char string1[7] = "Happy ";
    char string2[9] = "Holidays";
    char *greeting = stringMerge(string1, string2);
    printf("%s\n", greeting);
}