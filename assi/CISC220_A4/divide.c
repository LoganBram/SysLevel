#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int divide(int x, int y, int *rem, double *quot){ //*rem means to expect a memory address as rem
    //store remainder of int div in rem
    *rem = x % y; //derefences. sets value at memory address in rem, which is the variable remainder
    
    //store x/y float div in quot
    //!!instructions said floating point division but gives different answer then the example outputs
    
    *quot = (double)x/(double)y;

    //return x / y
    return x/y;

}


int main(int argc, char *argv[]){
    
    if(argc == 3){
        char *value = argv[1];
        int x = atoi(value);
        char *value2 = argv[2];
        int y = atoi(value2);
        int remainder;
        double quotient; //define variables remainder and quotient

        int ret = divide(x,y,&remainder,&quotient); //pass the address of remainder and quotient to divide function
        printf("%4d rem %4d\n%8.3f\n", ret, remainder, quotient);
    }
    else{
        fprintf(stderr, "Usage: divide int1 int2\n");
        exit(1);
        
    }
}
