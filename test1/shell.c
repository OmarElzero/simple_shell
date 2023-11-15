#include "MFheader.h"

int main(void) {
    char **argv;
    char *input;
    char *buf = NULL, *buf_cpy;
    size_t n;
    int i
    ;

    /* Check if the shell is in interactive mode*/
    int interactive_mode = isatty(STDIN_FILENO);

    while (1) {
        if (interactive_mode) {
            printf("$ ");
            fflush(stdout); /* Ensure the prompt is displayed immediately*/
        }

        /* Read input from the user*/
        if (getline(&buf, &n, stdin) == -1) {
            free(buf);
            break; /* Break the loop if getline fails (e.g., EOF)*/
        }
        remove_newline(buf);

        /* Check if the user wants to exit the shell*/
        if (strcmp(buf, "exit") == 0) {
            free(buf);
            break; /* Break the loop if the user types "exit"*/
        }

        /* Check if the user entered the "env" command*/
        if (strcmp(buf, "env") == 0) {
            /* Handle the env built-in command*/
            char **env_vars = environ;
            while (*env_vars != NULL) {
                printf("%s\n", *env_vars);
                env_vars++;
            }
            continue; 
        }
        if (!is_executable(buf)) {
            fprintf(stderr, "Command not found or not executable\n");
            continue; 
        }

        /* Duplicate the input buffer for further processing*/
        buf_cpy = strdup(buf);

        /* Tokenize the input to get the command and arguments*/
        argv = tokenize_input(buf, " \n");
        if (argv == NULL) {
            fprintf(stderr, "Error tokenizing input\n");
            free(buf_cpy);
            continue; 
        }

        /* Get the full path of the command*/
        input = get_path(argv[0]);
        if (input != NULL) {
            execute_command(argv);
            free(input);
        } else {
            fprintf(stderr, "Command not found in PATH\n");
        }

        /* Free allocated memory*/
        for (i = 0; argv[i] != NULL; i++) {
            free(argv[i]);
        }
        free(argv);
        free(buf_cpy);
    }

    free(buf);


    return 0;
}
