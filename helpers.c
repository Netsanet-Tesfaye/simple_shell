#include "shell.h"

#define TOKEN_DELIMITERS " \t\n"

char **split_line(char *line)
{
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        perror("split_line: allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOKEN_DELIMITERS);
    while (token != NULL)
    {
        tokens[position] = strdup(token);
        position++;

        if (position >= bufsize)
        {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                perror("split_line: allocation error");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIMITERS);
    }
    tokens[position] = NULL;
    return tokens;
}

void free_args(char **args)
{
    int i;
    if (args == NULL)
        return;

    for (i = 0; args[i] != NULL; i++)
    {
        free(args[i]);
    }
    free(args);
}

