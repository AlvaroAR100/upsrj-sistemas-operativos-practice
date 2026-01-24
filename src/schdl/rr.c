#include <stdio.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void rr_schedule(Process p[], int n, int quantum)
{
    int current_time = 0;
    int completed = 0;

    while (completed < n) {
        int progress = 0;

        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0 && p[i].arrival_time <= current_time) {

                progress = 1;

                if (p[i].remaining_time > quantum) {
                    // Ejecuta solo por el quantum
                    current_time += quantum;
                    p[i].remaining_time -= quantum;
                } else {
                    // Ejecuta hasta terminar
                    current_time += p[i].remaining_time;
                    p[i].remaining_time = 0;
                    p[i].completed = 1;
                    completed++;

                    // Cálculos finales
                    p[i].turnaround_time = current_time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                }
            }
        }

        // Si ningún proceso pudo ejecutarse, avanzamos el tiempo
        if (!progress) {
            current_time++;
        }
    }
}

/* ============================================================
 * DO NOT MODIFY MAIN
 * ============================================================ */
#ifndef UNIT_TEST
int main(void)
{
    int n;
    int quantum;

    printf("Número de procesos: ");
    scanf("%d", &n);

    printf("Quantum: ");
    scanf("%d", &quantum);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    rr_schedule(p, n, quantum);

    print_results(p, n, "RR Scheduling");
    return 0;
}
#endif
