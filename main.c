#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "sorts/list/list.h"
#include "sorts/selection_sort.h"

// gcc main.c sorts/list/list.c sorts/selection_sort.c sorts/printPerformance.c -o test

int create_vetor_in_file(char *file_name){
    FILE *file;
    file = fopen(file_name,"w");
    if(file == NULL){
        printf("Erro ao ler arquivo");
        return 1;
    }
    int i, n, size;

    printf("Vector lenght: ");
    scanf("%d", &size);

    for(i = 0; i < size; i++){
        n = rand() % (size * 10);
        fprintf(file, "%d ", n);
    }

    fclose(file);
}

int fileList(char *file_name, List *list, char action){
    FILE *file;
    int n;


    if(action == 'r'){
        file = fopen(file_name, "r");
        if(file == NULL){
            printf("Erro ao ler arquivo");
            return 1;
        }
        while(fscanf(file, "%d", &n) != EOF){
            insertList(list, n);
        }
    }else if(action == 'w'){
        file = fopen(file_name, "w");
        if(file == NULL){
            printf("Erro ao escrever arquivo");
            return 1;
        }
        Node *aux;
        for(aux = list->head; aux != NULL; aux = aux->next) fprintf(file, "%d ", aux->info);
    }

    fclose(file);
}

int main(){
    srand(time(NULL));
    char file_name[] = "arq.txt";
    create_vetor_in_file(file_name);

    List *list = createList();
    fileList(file_name, list, 'r');
    selectionSort(list);
    destroyList(list);
    
    return 0;
}