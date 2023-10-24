#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;
struct ListNode {
    int data;
    ListNode *next;
};
typedef struct ListNode *LinkedList;

size_t listTotal(const LinkedList t) {
    size_t sum = 0;
    ListNode *n = t;
    while (n) {
        sum += n->data;
        n = n->next;
    }
    return sum;
}

int main(void) {
    LinkedList t = NULL;
    printf("sum : %lu\n", listTotal(t));

    t = malloc(sizeof(ListNode));
    t->data = 1;
    t->next = NULL;
    printf("sum : %lu\n", listTotal(t));

    t->next = malloc(sizeof(ListNode));
    ListNode *n = t->next;
    n->data = 2;
    n->next = NULL;
    printf("sum : %lu\n", listTotal(t));

    n->next = malloc(sizeof(ListNode));
    n = n->next;
    n->data = 3;
    n->next = NULL;
    printf("sum : %lu\n", listTotal(t));
}