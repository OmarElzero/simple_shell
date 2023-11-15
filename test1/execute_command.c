#include "MFheader.h"
/**
 * 
 * 
 * 
 * 
*/
void execute_command(char **argv) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("Error forking");
    } else if (child_pid == 0) {
        if (execve(argv[0], argv, environ) == -1) {
            perror("Error executing command");
        }
        exit(0);
    } else {
        wait(NULL);
    }
}
