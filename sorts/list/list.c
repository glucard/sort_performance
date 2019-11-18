#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List * createList(){
    List * L = (List*) malloc(sizeof(List));
    L->head = NULL;
    int lenght = 0;
    return L;
}

int isEmpty(List *L){
    return (L->head == NULL);
}

void insertList(List *L, int input){
    Node *new = (Node*) malloc(sizeof(Node));
    L->lenght++;
    new->info = input;
    new->next = L->head;
    L->head = new;
}

void printList(List *L){
    Node *runner;
    for(runner = L->head; runner != NULL; runner = runner->next)printf("%i, ", runner->info);
    printf("\n");
}

void destroyList(List *L){
    Node *previous;
    while(L->head != NULL){
        previous = L->head;
        L->head = L->head->next;
        free(previous);
    }
    free(L->head);
    free(L);
}