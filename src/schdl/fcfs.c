#include <stdio.h>
#include <stdlib.h>
#include "process.h"

int main() {
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

    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival_time) {
            time = p[i].arrival_time;
        }

        printf("Tiempo %d: Ejecutando P%d (BT=%d)\n",
               time, p[i].id, p[i].burst_time);

        p[i].waiting_time = time - p[i].arrival_time;
        time += p[i].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        p[i].completed = 1;
    }

    print_results(p, n, "FCFS Scheduling");

    free(p);
    return 0;
}
