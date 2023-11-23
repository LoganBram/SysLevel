#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack_utils.h"




int main(void) {



    stack* s = stack_init_empty(); 

    stack_is_sorted(s, double_less_than);
}