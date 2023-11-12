#ifndef MFHEADER_H
#define MFHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

/*handle string*/
int MF_strlen(char *s);
int MF_strcmp(char *s1, char *s2);
char *MF_strdup(char *str);
char *MF_strcat(char *dest, char *src);


char *_getenv(const char *name);
char *get_path(char *command);
void remove_newline(char *str);
char **tokenize_input(char *input, char *delim);
int is_executable(char *command);
void execute_command(char **argv);
int handle_cd(char **argv);
#endif

