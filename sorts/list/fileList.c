#include <stdio.h>
#include <stdlib.h>
#include "fileList.h"

int create_vetor_in_file(char *file_name){
    FILE *file;
    file = fopen(file_name,"w");
    if(file == NULL){
        printf("Erro ao ler arquivo");
        return 0;
    }
    int i, n, size;

    printf("Vector lenght: ");
    scanf("%d", &size);

    for(i = 0; i < size; i++){
        n = rand() % (size * 10);
        fprintf(file, "%d ", n);
    }

    fclose(file);
    return 1;
}

int fileList(char *file_name, List *list, char action){
    FILE *file;
    int n;


    if(action == 'r'){
        file = fopen(file_name, "r");
        if(file == NULL){
            printf("Erro ao ler arquivo");
            return 0;
        }
        while(fscanf(file, "%d", &n) != EOF){
            insertList(list, n);
        }
    }else if(action == 'w'){
        file = fopen(file_name, "w");
        if(file == NULL){
            printf("Erro ao escrever arquivo");
            return 0;
        }
        Node *aux;
        for(aux = list->head; aux != NULL; aux = aux->next) fprintf(file, "%d ", aux->info);
    }
    fclose(file);
    return 1;
}