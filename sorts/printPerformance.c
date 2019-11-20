#include <stdio.h>
#include "printPerfomance.h"

void printSortPerformance(char *sort_name, unsigned long long int comparassions, unsigned long long int changes, clock_t t){
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("---------------------------------\n");
    printf("%s\n", sort_name);
    printf("-Comparassions: %llu\n", comparassions);
    printf("-Changes: %llu\n", changes);
    printf("-Time to execute %fs\n", time_taken);
    printf("---------------------------------\n");
}