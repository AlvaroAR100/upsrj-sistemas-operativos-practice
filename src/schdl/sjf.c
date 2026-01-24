#include <stdio.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void sjf_schedule(Process p[], int n)
{
    int time = 0;
    int completed = 0;
    int visited[n];
    Process result[n];

    // Inicializar visitados
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    while (completed < n) {
        int min_bt = 999999;
        int idx = -1;

        /* Buscar el proceso más corto que ya haya llegado */
        for (int i = 0; i < n; i++) {
            if (!visited[i] && p[i].arrival_time <= time) {
                if (p[i].burst_time < min_bt) {
                    min_bt = p[i].burst_time;
                    idx = i;
                }
            }
        }

        /* Si no hay proceso disponible, el CPU queda ocioso */
        if (idx == -1) {
            time++;
            continue;
        }

        /* Marcar proceso como ejecutado */
        visited[idx] = 1;

        /* Calcular tiempos */
        p[idx].waiting_time = time - p[idx].arrival_time;
        p[idx].turnaround_time = p[idx].waiting_time + p[idx].burst_time;
        time += p[idx].burst_time;
        p[idx].completed = 1;

        /* Guardar orden de ejecución */
        result[completed] = p[idx];
        completed++;
    }

    /* Copiar el orden final al arreglo original */
    for (int i = 0; i < n; i++) {
        p[i] = result[i];
    }
}
/* ============================================================
 * DO NOT MODIFY MAIN
 * ============================================================ */
#ifndef UNIT_TEST
int main(void)
{
    int n;
    printf("Número de procesos: ");
    scanf("%d", &n);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    sjf_schedule(p, n);

    print_results(p, n, "SJF Scheduling");
    return 0;
}
#endif