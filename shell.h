#ifndef SHELL_H
#define SHELL_H

int execute_command(const char *command, char *args[]);
int parse_command(const char *input, char *command, char *args[]);
char *read_line(void);

#endif /* SHELL_H */

