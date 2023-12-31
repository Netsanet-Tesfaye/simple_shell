#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	{
    char *line;
    char **args;
    int status;

    signal(SIGINT, handle_ctrl_c);

    do
    {
        print_prompt();
        line = read_line();
        args = split_line(line);
        status = execute(args);

        free(line);
        free_args(args);
    } while (status);

    return EXIT_SUCCESS;
}
}
