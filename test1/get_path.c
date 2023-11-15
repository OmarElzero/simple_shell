#include "MFheader.h"
char *get_path(char *command) {

    char *token;
    char *full_path;

    char *path_env = getenv("PATH");
    if (!path_env) {
        fprintf(stderr, "Error: PATH environment variable not found\n");
        return NULL;
    }

    token = strtok(path_env, ":");
    while (token) {
        full_path = malloc(strlen(token) + strlen(command) + 2); /* +2 for '/' and '\0'*/
        if (!full_path) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        sprintf(full_path, "%s/%s", token, command);

        if (access(full_path, X_OK) == 0) {
            return full_path; /* Found executable path*/
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    fprintf(stderr, "Error: Command not found or not executable\n");
    return NULL;
}


