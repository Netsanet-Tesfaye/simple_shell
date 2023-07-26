#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024

void execute_command(char *command) {
    /* ... (Same code for executing a command using fork and execve) */
    /* Implement the details of the execute_command function here. */
    (void)command; /* Suppress unused parameter warning */
}

void print_environment() {
    /* Get the external environment variables using 'extern' */
    extern char **environ;
    int i;
    for (i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}

int main(int argc, char *argv[]) {
    char command[MAX_COMMAND_LENGTH];

    if (argc == 1) {
        /* Interactive mode */
        while (1) {
            printf("($) ");
            if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
                /* End of file (Ctrl+D) condition */
                printf("\n");
                break;
            }

            /* Remove the trailing newline character */
            command[strcspn(command, "\n")] = '\0';

            if (strcmp(command, "exit") == 0) {
                break;
            } else if (strcmp(command, "env") == 0) {
                print_environment();
            } else {
                execute_command(command);
            }
        }
    } else if (argc == 2) {
        /* Non-interactive mode, read commands from a file or input stream */
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("File open error");
            exit(EXIT_FAILURE);
        }

        while (fgets(command, MAX_COMMAND_LENGTH, file) != NULL) {
            /* Remove the trailing newline character */
            command[strcspn(command, "\n")] = '\0';

            if (strcmp(command, "exit") == 0) {
                break;
            } else if (strcmp(command, "env") == 0) {
                print_environment();
            } else {
                execute_command(command);
            }
        }

        fclose(file);
    } else {
        fprintf(stderr, "Usage: %s [file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    return 0;
}

