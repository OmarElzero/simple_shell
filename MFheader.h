#ifndef MFHEAD_H
#define MFHEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_PL 1024
#define MAX_CL 268
extern char **environ;

/*handle string*/
int MF_strlen(char *s);
int MF_strcmp(char *s1, char *s2);
char *MF_strdup(char *str);
char *MF_strcat(char *dest, char *src);

/*prompt*/
void Prompt(void);

/*parsing*/
char **putstrtok(char *linebuff, char *d);

/*path*/
char *MF_fullpath(char *flname);
/*free*/
void freenfr(char *str);
void freearr(char **arrtf);

/*proccesses*/
void execution(char *pathname, char **argv, char *linebuff, char **environ);
void _getline(char **linebuff, size_t *buffsize);
void nonInterproc(void);
void interproc(void);

#endif
