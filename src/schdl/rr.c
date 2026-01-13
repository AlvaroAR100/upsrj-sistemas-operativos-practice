#include <stdio.h>
#include "process.h"

int main() {
    int n;
    printf("Número de procesos: ");
    scanf("%d", &n);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    // TODO: Aquí va la lógica del scheduler
    
    print_results(p, n, "RR Scheduling");
    return 0;
}