#include "read_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* Include the <string.h> header to fix the error */

ssize_t read_line(char *buffer, size_t bufsize)
{
    if (getline(&buffer, &bufsize, stdin) == -1)
        return -1;

    buffer[strcspn(buffer, "\n")] = '\0';

    return bufsize;
}

