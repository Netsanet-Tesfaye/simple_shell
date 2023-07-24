#ifndef PATH2_H
#define PATH2_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024

int shell(void);
void init_shell(void);
int main(int argc, char *argv[]);

#endif

