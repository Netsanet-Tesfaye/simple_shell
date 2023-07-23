#include "shell.h"

void handle_ctrl_c(int signal)
{
    (void)signal;
    write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}

/* You can add more error-handling functions here if needed */

