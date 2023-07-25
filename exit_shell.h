#ifndef EXIT_SHELL_H
#define EXIT_SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void shell(void);
int shell_entry_point(void);

int _strcmp(const char *str1, const char *str2);

#endif
