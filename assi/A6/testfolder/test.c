#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[] = "12,2,3,6";
    int count = 0;

    // Iterate through string and count commas
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',') {
            count++;
        }
    }

    printf("Number of commas in the string: %d\n", count);
    int arr[count+1];

    //use strtok(string,",")
    char *token = strtok(str, ",");
    int value = atoi(token);
    //add to array
    arr[0] = value;

   //for loop of comma count +1
    for(int i = 1; i < count+1; i++){
        token = strtok(NULL, ",");
        value = atoi(token);
        arr[i] = value;
    }
    //token = strtok(NULL, ",")
    //conver token using atoi
    //store in array at i of for loop
    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", arr[2]);
    printf("%d\n", arr[3]);

    return 0;
}

