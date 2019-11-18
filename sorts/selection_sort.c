#include <stdio.h>
#include <stdlib.h>
#include "selection_sort.h"
#include "printPerfomance.h"

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int isSmaller(Node *a, Node *b){
    return (a->info < b->info);
}

void selectionSort(List *L){
    Node *i, *j;
    Node *smallest;
    clock_t t; 
    t = clock(); 
    int changes = 0, comparissions = 0;
    for(i = L->head; i != NULL; i = i->next){
        smallest = i;
        for(j = i; j != NULL; j = j->next){
            comparissions++;
            if(isSmaller(j, smallest)){
                changes++;
                smallest = j;
            }
        }
        swap(&smallest->info, &i->info);
    }
    printSortPerformance("Selection Sort", comparissions, changes, t); 
}
