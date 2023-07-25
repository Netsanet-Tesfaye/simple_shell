/* builtins.c */

#include "shell.h"
#include <stddef.h>
#include <unistd.h>
#include <string.h>

/**
 * _env - Print the current environment variables.
 *
 * Return: Always returns 0.
 */
int _env(void)
{
	int i;

	extern char **environ; /* Declare 'environ' as an external variable */

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	return (0);
}

