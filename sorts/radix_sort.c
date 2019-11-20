#include <stdio.h>
#include <stdlib.h>

#include "list/list.h"

int getIndex(int n, int pos){
    return (n / pos) % 10;
}

void radixSort(List *list){
    Node *ni;
    List **bucket = (List**) malloc(10*sizeof(List*));
    int maior = list->head->info;
    for(ni = list->head->next; ni != NULL; ni = ni->next)
        if(ni->info > maior) maior = ni->info;

    int i;

	for (i = 0; i < 10; i++) {
		bucket[i] = createList();
	}

    int exp = 1;
    while(maior/exp > 0){
        for(ni = list->head; ni != NULL; ni = ni->next){
            insertList(bucket[getIndex(ni->info, exp)], ni->info);
        }
        destroyList(list);
		list = createList();
		list->head = bucket[0]->head;
		Node* last = NULL;
        for(i = 0; i < 9; i++){
            for(ni = bucket[i]->head; ni != NULL; ni = ni->next){
                last = ni;
                bucket[i] = createList();
            }
            bucket[i] = createList();
			if (last != NULL)last->next = bucket[i + 1]->head;
			else list->head = bucket[i + 1]->head;
        }
        bucket[9] = createList();
        exp *= 10;
    }
    printList(list);
	printf("aaa");
}