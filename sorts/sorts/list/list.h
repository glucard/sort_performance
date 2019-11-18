#ifndef _LIST_H_
#define _LIST_H_

typedef struct node {
    int info;
    struct node *next;
} Node;

typedef struct list {
    int lenght;
    Node *head;
} List;

List * createList();
int isEmpty(List *L);
void insertList(List *L, int input);
int removeList(List *L, int value);
void printList(List *L);
void destroyList(List *L);


#endif