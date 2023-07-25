#include "exit_shell.h"

/**
 * shell - name of the function.
 *
 * Return: no return.
 */

void shell(void)
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
}

/**
 * shell_entry_point - name of the function.
 *
 * Return: 0 - successful
 * non-zero value - error(unsuccess).
 */

int shell_entry_point(void)
{
	shell();
	return (0);
}
