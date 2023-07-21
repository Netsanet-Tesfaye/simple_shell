#include "parse_command.h"
#include <stdio.h>
#include <string.h>

int parse_command(const char *input, char *command, char *args[])
{
    int arg_count = 0;
    char *token;

    token = strtok((char *)input, " \t\n");
    if (token == NULL)
        return 0;

    strcpy(command, token);

    while (token != NULL)
    {
        args[arg_count] = token;
        arg_count++;

        token = strtok(NULL, " \t\n");
    }

    args[arg_count] = NULL;

    return arg_count;
}

