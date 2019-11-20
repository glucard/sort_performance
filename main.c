#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "sorts/list/list.h"
#include "sorts/list/fileList.h"
#include "sorts/selection_sort.h"
#include "sorts/insertion_sort.h"
#include "sorts/bubble_sort.h"
#include "sorts/radix_sort.h"

// gcc main.c sorts/list/list.c sorts/list/fileList.c sorts/selection_sort.c sorts/insertion_sort.c sorts/bubble_sort.c sorts/radix_sort.c sorts/printPerformance.c -o test


int main(){
    // srand(time(NULL));
    char file_name[] = "arq.txt";
    create_vetor_in_file(file_name);
    List *list;
    
	list = createList();
	fileList(file_name, list, 'r');
	selectionSort(list);
	destroyList(list);

	list = createList();
	fileList(file_name, list, 'r');
	insertionSort(list);
	destroyList(list);

	list = createList();
	fileList(file_name, list, 'r');
	bubbleSort(list);
	destroyList(list);
    
    return 0;
}