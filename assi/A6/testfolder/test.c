#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    int c;
    const size_t max_length = 10; // Define max_length as needed
    char s[max_length + 1]; // Array to store the characters, +1 for the null terminator

    f = fopen("enc01.txt", "r");
    if (f == NULL) {
        perror("Error opening file");
        return -1;
    }

    size_t i;
    for (i = 0; i < max_length; i++) {
        c = fgetc(f);
        if (c != EOF) {
            if (c == '\n') {
                printf("\\n encountered\n");
                break; // Stop reading after a newline
            }
            else {
                s[i] = c;
            }
        }
    }

    s[i] = '\0'; // Null-terminate the string
    fclose(f);

    // Print the array as a string
    printf("%s\n", s);

    return 0;
}

