#include "shell.h"
#include "string_utils.h"
#include <string.h>

#define MAX_PATH_LENGTH 1024

/**
 * shell - name of function.
 *
 * Return: always return 0.
 */

int shell(void)
{
	 char command[256];
	 char path[MAX_PATH_LENGTH];
	 const char *delimiter = ":";
	 const char *command_not_found = "Command not found: ";
	 const char *exit_command = "exit";
	 int exit_command_length = 4;

	 char *env_path = getenv("PATH");
	 size_t len;
	 int is_exit;
	 int i;

	 while (1)
	 {
		 char *dir;
		 int command_found = 0;

		 write(STDOUT_FILENO, "Enter a command: ", 17);
		 read(STDIN_FILENO, command, sizeof(command));

		 len = _strlen(command);
		 if (len > 0 && command[len - 1] == '\n')
		 {
			 command[len - 1] = '\0';
		 }

		 is_exit = 1;
		 for (i = 0; i < exit_command_length; i++)
		 {
			 if (_strcmp(command + i, exit_command + i) != 0)
			 {
				 is_exit = 0;
				 break;
			 }
		 }

		 if (is_exit)
		 {
			 write(STDOUT_FILENO, "Exiting the shell...\n", 21);
			 break;
		 }

			 dir = strtok(env_path, delimiter);


			 while (dir != NULL)
			 {
				 size_t dir_len = _strlen(dir);
				 size_t command_len = _strlen(command);
				 size_t path_len = 0;

				 if (dir_len + 1 + command_len + 1 <= MAX_PATH_LENGTH)
				 {
					 _strcpy(path, dir);
					 path_len = dir_len;

					 path[path_len++] = '/';

					  _strcpy(path + path_len, command);
					  path_len += command_len;

					  path[path_len] = '\0';

					  if (access(path, X_OK) == 0)
					  {
						  command_found = 1;
						  break;
					  }
				 }

				 dir = strtok(NULL, delimiter);
			 }

			 if (command_found)
			 {
				 pid_t pid = fork();

				 if (pid == -1)
				 {
					 perror("fork");
					 _exit(1);
				 }
				 else if (pid == 0)
				 {
					 execl(path, command, NULL);

					 write(STDOUT_FILENO, command_not_found, _strlen(command_not_found));
					 write(STDOUT_FILENO, command, _strlen(command));
					 write(STDOUT_FILENO, "\n", 1);

					  _exit(1);
				 }
				 else
				 {
					 waitpid(pid, NULL, 0);
				 }
			 }
			 else
			 {
				 write(STDOUT_FILENO, command_not_found, _strlen(command_not_found));
				 write(STDOUT_FILENO, command, _strlen(command));
				 write(STDOUT_FILENO, "\n", 1);
			 }
		 }

		 return (0);
}

/**
 * init_shell - function declaration.
 *
 * Return: no return.
 */

void init_shell(void)
{
	shell();
}

/**
 * main - entry point.
 *
 * Return: 0 - successful execution.
 * non-zero value - an error.
 */

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	init_shell();
	return (0);
}
