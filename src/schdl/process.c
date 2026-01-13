#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "process.h"

void read_processes(Process p[], int n) {
    srand(time(NULL)); // Semilla para números aleatorios
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        // Arrival time aleatorio entre 0 y 10
        p[i].arrival_time = rand() % 10;
        // Burst time aleatorio entre 1 y 10
        p[i].burst_time = (rand() % 10) + 1;
    }
}

// Inicialización de campos comunes
void init_processes(Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].remaining_time = p[i].burst_time;
        p[i].waiting_time = 0;
        p[i].turnaround_time = 0;
        p[i].completed = 0;
    }
}

// Impresión de resultados en tabla
void print_results(Process p[], int n, const char *title) {
    printf("\n%s\n", title);
    printf("ID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n",
               p[i].id,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].waiting_time,
               p[i].turnaround_time);
    }
}