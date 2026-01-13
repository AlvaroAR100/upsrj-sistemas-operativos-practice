#include <stdio.h>
#include <string.h>
#include "shell_exec.h"

#define MAX_LINE 256
#define MAX_ARGS 16

int main(void)
{
    char line[MAX_LINE];
    char *argv[MAX_ARGS];
    int i;

    printf("MiniShell (type 'exit' to quit)\n");

    while (1)
    {
        printf("mini-shell> ");
        fflush(stdout);

        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            break;
        }

        if (strncmp(line, "exit", 4) == 0)
        {
            break;
        }

        /* Tokenize input */
        i = 0;
        argv[i] = strtok(line, " \n");

        while (argv[i] != NULL && i < MAX_ARGS - 1)
        {
            i++;
            argv[i] = strtok(NULL, " \n");
        }

        execute_command(argv);
    }

    return 0;
}
