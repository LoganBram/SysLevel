#include <stdio.h>

int main() {
    FILE *file;
    int value;

    // Open the file for reading
    file = fopen("enc01.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read integers separated by commas and/or whitespace
    while (fscanf(file, " %d,", &value) == 1) {
        //store in array
    }

    // Close the file
    fclose(file);

    return 0;
}
