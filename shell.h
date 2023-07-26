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
#include <dirent.h>
#include <stddef.h> /* For size_t and NULL */

#define BUFFER_SIZE 1024

/* Function Prototypes */
void print_prompt(void);
char *read_line(void);
char **split_line(char *line);
int execute(char **args);
void free_args(char **args);
void handle_ctrl_c(int signal);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
size_t _strlen(const char *str);
int shell(void);
void init_shell(void);
int shell_entry_point(void);


#endif /* SHELL_H */

