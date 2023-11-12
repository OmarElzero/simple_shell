#include "MFheader.h"
/**
 * 
 * 
 * 
*/
int is_executable(char *command) {
    if (access(command, X_OK) == -1) {
        perror("Error: Command not found or not executable");
        return 0;  /* Indicate that the command is not executable*/
    }

    return 1;  /* Indicate that the command is executable*/
}
