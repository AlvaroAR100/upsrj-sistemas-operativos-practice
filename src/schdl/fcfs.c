#include <stdio.h>
#include <stdlib.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void fcfs_schedule(Process p[], int n)
{
    (void)p;
    (void)n;
    /* TODO: Implement FCFS scheduling algorithm here */
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
