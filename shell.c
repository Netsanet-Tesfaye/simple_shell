#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "execute_command.h"
#include "parse_command.h"
#include "read_line.h"

extern char **environ;

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64
#define PROMPT "#cisfun$ "

/**
 * execute_command - Execute a given command.
 * @command: The command to be executed.
 * @args: Array of arguments for the command.
 *
 * Return: 1 on success, 0 on failure.
 */
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
		/* Child process */
		execve(command, args, environ);

		/* execve only returns if an error occurred */
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		int status;
		wait(&status);

		if (WIFEXITED(status))
			return 1; /* Command executed successfully */
		else
		{
			fprintf(stderr, "./shell: Command execution failed\n");
			return 0;
		}
	}
}

/**
 * parse_command - Parse the user input into a command and arguments.
 * @input: The user input.
 * @command: The command extracted from the input.
 * @args: The arguments extracted from the input.
 *
 * Return: The number of arguments.
 */
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

	args[arg_count] = NULL; /* Set the last argument to NULL as execve expects it. */

	return arg_count;
}

/**
 * main - Simple UNIX shell main function.
 *
 * Return: Always 0.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char exec_command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];
	int arg_count;

	while (1)
	{
		printf("%s", PROMPT);

		/* Read user input */
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			/* Handle end of file condition (Ctrl+D) */
			printf("\n");
			break;
		}

		/* Remove the newline character at the end */
		command[strcspn(command, "\n")] = '\0';

		/* Check if the user entered "exit" to quit the shell */
		if (strcmp(command, "exit") == 0)
			break;

		/* Parse the command and arguments */
		arg_count = parse_command(command, exec_command, args);

		/* Execute the command */
		if (arg_count > 0)
		{
			if (!execute_command(exec_command, args))
				fprintf(stderr, "./shell: No such file or directory\n");
		}
	}

	return EXIT_SUCCESS;
}

