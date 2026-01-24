#include <stdio.h>
#include <stdlib.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void fcfs_schedule(Process p[], int n)
{
    int current_time = 0;

    // Ordenar procesos por arrival_time (FCFS)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[j].arrival_time < p[i].arrival_time) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Simulación FCFS
    for (int i = 0; i < n; i++) {

        // Si el CPU está libre, avanzar al tiempo de llegada
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;
        }

        // Tiempo de espera
        p[i].waiting_time = current_time - p[i].arrival_time;

        // Ejecutar proceso completo
        current_time += p[i].burst_time;

        // Tiempo de retorno
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;

        p[i].completed = 1;
    }
}

/* ============================================================
 * DO NOT MODIFY MAIN
 * ============================================================ */
#ifndef UNIT_TEST
int main(void)
{
    int n;
    int time = 0;

    printf("Número de procesos: ");
    scanf("%d", &n);

    Process *p = malloc(n * sizeof(Process));
    if (p == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    read_processes(p, n);
    init_processes(p, n);

    fcfs_schedule(p, n);

    print_results(p, n, "FCFS Scheduling");

    free(p);
    return 0;
}
#endif
