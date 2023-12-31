#include "shell.h"

/**
 * shell - name of the function.
 *
 * Return: no return.
 */

int shell(void)
{
	char input[BUFFER_SIZE];

	 while (1)
	 {
		 write(STDOUT_FILENO, "Shell> ", 8);

		 if (read(STDIN_FILENO, input, sizeof(input)) == -1)
			 break;

		 input[strcspn(input, "\n")] = '\0';

		 if (_strcmp(input, "exit") == 0)
		 {
			 write(STDOUT_FILENO, "Exiting the shell...\n", 21);
			 break;
		 }

		 memset(input, 0, sizeof(input));
	 }

	 write(STDOUT_FILENO, "\n", 1);

	return (0);
}
