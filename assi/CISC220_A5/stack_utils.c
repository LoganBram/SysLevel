#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack_utils.h"


stack *stack_split_at(stack *s, size_t index) {
    node *n = s->top;
    for (int i = 0; i < s->size; i++) {
        
        if (i < index ) {
            printf("new %d\n", *((int*)n->elem));
            // move 

        }
        else{
            printf("%d\n", *((int*)n->elem));
        }
        n = n->next;  // Move to the next node
    }

    
}