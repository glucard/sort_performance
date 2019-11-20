#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#include "bubble_sort.h"
#include "printPerfomance.h"

void swapB(Node *a, Node *b){
    int aux = a->info;
    a->info = b->info;
    b->info = aux;
}

int isBigger(Node *a, Node *b){
    return (a->info > b->info);
}

void bubbleSort(List *list){
    Node *last = NULL;
    Node *i;
    clock_t t; 
    t = clock(); 
    unsigned long long int changes = 0, comparissions = 0;
    while (list->head != last){
        for (i = list->head; i->next != last; i = i->next){
            comparissions++;
            if (isBigger(i, i->next)){
                changes++;
                swapB(i, i->next);
            }
        }
        last = i;
    }
    printSortPerformance("Bubble Sort", comparissions, changes, t); 
}