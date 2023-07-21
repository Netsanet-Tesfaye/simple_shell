#include "execute_command.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

int execute_command(const char *command, char *args[])
{
    pid_t pid = fork();

    if (pid == -1)
    {
        fprintf(stderr, "./shell: Fork failed\n");
        return 0;
    }
    else if (pid == 0)
    {
        execve(command, args, environ);
        perror("./shell");
        exit(EXIT_FAILURE);
    }
    else
    {
        int status;
        wait(&status);

        if (WIFEXITED(status))
            return 1;
        else
        {
            fprintf(stderr, "./shell: Command execution failed\n");
            return 0;
        }
    }
}

