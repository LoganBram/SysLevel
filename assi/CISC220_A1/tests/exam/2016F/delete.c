#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;
struct ListNode {
    int data;
    ListNode *next;
};
typedef struct ListNode *LinkedList;

int deleteSecond(LinkedList list) {
    if (!list || !list->next) {
        return 0;
    }
    ListNode *sec = list->next;
    list->next = sec->next;
    sec->next = NULL;
    int res = sec->data;
    free(sec);
    return res;
}

void printList(LinkedList list) {
    printf("[");
    ListNode *n = list;
    if (n) {
        printf("%d", n->data);
        n = n->next;
        while (n) {
            printf(", %d", n->data);
            n = n->next;
        }
    }
    printf("]\n");
}

int main(void) {
    LinkedList t = NULL;
    printList(t);

    t = malloc(sizeof(ListNode));
    t->data = 1;
    t->next = NULL;

    t->next = malloc(sizeof(ListNode));
    ListNode *n = t->next;
    n->data = 2;
    n->next = NULL;
    printList(t);

    int del = deleteSecond(t);
    printList(t);
    
}