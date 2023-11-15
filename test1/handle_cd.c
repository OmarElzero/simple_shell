#include "MFheader.h"
/**
 * 
 * 
 * 
 * 
*/
int handle_cd(char **argv) {
    if (argv[1] == NULL) {
        fprintf(stderr, "cd: missing argument\n");
        return -1;
    }

    if (chdir(argv[1]) != 0) {
        perror("cd");
        return -1;
    }

    return 0;
}
