#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "hello, world, this is a test string";
    int count = 0;

    // Iterate through string and count commas
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',') {
            count++;
        }
    }

    printf("Number of commas in the string: %d\n", count);


    //use strtok(string,",")
   printf(str);

   //for loop of comma count +1
    //token = strtok(NULL, ",")
    //conver token using atoi
    //store in array at i of for loop
    // Further processing can be done here if needed, like using strtok
    // But remember, strtok modifies the original string

    return 0;
}

