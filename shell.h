#ifndef SHELL_H
#define SHELL_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <stddef.h> /* For size_t and NULL */

/* Function Prototypes */
void print_prompt(void);
char *read_line(void);
char **split_line(char *line);
int execute(char **args);
void free_args(char **args);
void handle_ctrl_c(int signal);
int _env(void);


#endif /* SHELL_H */

