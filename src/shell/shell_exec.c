#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell_exec.h"

/*------------------------------------------------------------
 * TODO:
 * Implement process creation and command execution
 * using fork(), execvp() and wait().
 *-----------------------------------------------------------*/
void execute_command(char *argv[])
{
    /* TODO: Student must implement:
     *  - fork()
     *  - execvp() in child
     *  - wait() in parent
     */

    (void)argv;
}
