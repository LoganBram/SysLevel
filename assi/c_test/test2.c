#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elements;
    size_t size;
} list;


void main(){
    list mylist;
    mylist.size = 3;
    mylist.elements = malloc(sizeof(int) * mylist.size);

    // Initialize the elements (for example)
    mylist.elements[0] = 10;
    mylist.elements[1] = 20;
    mylist.elements[2] = 30;

    printf("%d\n", mylist.elements[2]);
    free(mylist.elements);
}