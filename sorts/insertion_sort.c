#include <stdio.h>
#include <stdlib.h>

#include "insertion_sort.h"
#include "printPerfomance.h"

int isSmallerQ(Node *a, Node *b){
    return (a->info < b->info);
}

void insertionSort(List *list){
    Node *i, *j;
    Node *ant_i = NULL, *ant_j = NULL;
    //--performance--
    clock_t t;
    t = clock();
    unsigned long long int changes = 0, comparissions = 0;
    //---------------

    for(i = list->head; i != NULL; i = i->next){
        ant_j = NULL;
        for(j = list->head; j != i; j = j->next){
            comparissions++;
            if(isSmallerQ(i, j)){
                changes++;
                ant_i->next = i->next;
                if(ant_j == NULL) list->head = i;
                else ant_j->next = i;
                i->next = j;
                i = ant_i;
                break;
            }
            ant_j = j;
        }
        ant_i = i;
    }
    printSortPerformance("Selection Sort", comparissions, changes, t);
}