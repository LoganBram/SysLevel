#include <stdio.h>
#include <stdlib.h>

/*
 * Prints the values of a on a single line with no space between
 * the values. Prints a newline character after printing all of
 * the array values.
 * 
 * Values are printed left to right starting from a[0] and ending with a[7].
 */
void print(int a[static 8]) {   
    for(int i =0; i < 8; i++){
        printf("%d", a[i]);
        
    }
    printf("\n");

}

/*
 * Translates a string str consisting of '0' and '1' characters
 * into an array bin consisting of 0 and 1 integer values. For
 * example, the string "00000001" results in the array bin
 * having the values bin[0] = 0, bin[1] = 0, ..., bin[7] = 1.
 */
void tobinary(char str[static 8], int bin[static 8]) {
    //iterate through str input, convert each to int
    for (int i = 0; i < 8; i++){
       int x = str[i] - '0'; // Convert character to integer
        bin[i] = x;
    }
    
}

/*
 * Sums the 8-digit binary values x and y storing the result
 * in z. The sum is computed using the standard long
 * addition algorithm from grade school.
 */
int sum(int x[static 8], int y[static 8], int z[static 8]) {
    int carry = 0;
    for (int i = 7; i >= 0; i--) {
        // Add the corresponding bits of x and y along with the carry
        int total = x[i] + y[i] + carry;

        // If the total is 2 or 3, there is a carry
        if (total > 1) {
            z[i] = total % 2; // Store the bit (0 or 1) in the result
            carry = 1; // Set carry for the next bit addition
        } else {
            z[i] = total; // Store the bit in the result
            carry = 0; // No carry for the next bit addition
        }
    }
    
    // The function returns the final carry, which can be important 
    // if the caller needs to know if there was an overflow
    return carry;

}



int main(int argc, char *argv[]){
    int arr1[8];
    int arr2[8];
    int answ[8];
    if(argc == 3){
        tobinary(argv[1],arr1);
        tobinary(argv[2],arr2);

        int carry = sum(arr1,arr2,answ);
        print(answ);
        if(carry != 0){
            printf("overflow\n");
        }
    
        

    }else{
        printf("%d", 2);
    }
    
}