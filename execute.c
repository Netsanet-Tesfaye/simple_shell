#include "shell.h"

int execute(char **args)
{
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return 1;

    pid = fork();
    if (pid == 0)
    {
        if (execve(args[0], args, NULL) == -1)
        {
            perror(args[0]);
            _exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        perror("fork");
    }
    else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

