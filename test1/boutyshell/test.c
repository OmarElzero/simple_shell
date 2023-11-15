#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_PL 1024
#define MAX_CL 268


extern char **environ;

void freenfr(char *str)
{
	if (str != NULL)
	{
		free(str);
	}
}
char *MF_fullpath(char *flname)
{
	char *path;
	char *patcp;
	char *getdir;
	char *fpath;
	if (access(flname,X_OK) == 0)
	{
		return(flname);
	}
	else
	{
	path = getenv("PATH");
	patcp = strdup(path);
	fpath = malloc(MAX_PL);

	getdir = strtok(patcp, ":");

	while (getdir)
	{
		strcpy(fpath, getdir);
		strcat(strcat(fpath, "/"), flname);

		if (access(fpath, X_OK) == 0)
		{
			freenfr(patcp);
			return(fpath);
		}
		getdir = strtok(NULL, ":");
	}
	}

	freenfr(patcp);
	freenfr(fpath);
	return NULL;
}
void execution(char *pathname, char **argv, char *linebuff, char **environ)
{   pid_t child_pid;
	if (pathname == NULL)
	{
		perror("command");
		return;
	}

	if ((child_pid = fork()) == -1)
	{
		perror("fork");
		freenfr(linebuff);
		freenfr(pathname);
		exit(EXIT_FAILURE);
	}


	if (child_pid == 0)
	{
		if (execve(pathname, argv, environ) == -1)
		{
			perror("execve");
			fprintf(stderr, "Error executing command: %s\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;
		waitpid(child_pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "Command failed with exit status %d\n", WEXITSTATUS(status));
		}
	}

	freenfr(pathname);
}

void readInput(char **linebuff, size_t *buffsize)
{
	ssize_t line = getline(linebuff, buffsize, stdin);
	if (line == -1 || *linebuff == NULL)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	(*linebuff)[line - 1] = '\0';

}

void freeArgs(char **argv)
{
	int i;
	for ( i = 0; argv[i] != NULL; i++)
	{
		freenfr(argv[i]);
	}
	free(argv);
}


char **putstrtok(char *linebuff, char *d) {
    char **parsed = NULL;
    int argc = 0;
    int i = 0;
    char *linebuff_copy = strdup(linebuff);

    char *token = strtok(linebuff_copy, d);
    while (token) {
        size_t token_len = strlen(token);
        char *null_terminated_token = malloc(token_len + 1);
        strcpy(null_terminated_token, token);

        parsed = realloc(parsed, sizeof(char *) * (argc + 1));
        parsed[i] = null_terminated_token;

        i++;
        argc++;

      
        while (*token && strchr(d, *token))
            token++;

        token = strtok(NULL, d);
    }

   
    parsed = realloc(parsed, sizeof(char *) * (argc + 1));
    parsed[i] = NULL;

    free(linebuff_copy);
    return parsed;
}

void interproc()
{
	char *linebuff = NULL;
	size_t buffsize = 0;
	char **argv;

	while (1)
	{
		char *fp;
		printf("BoutomrSHELL  :");
		readInput(&linebuff, &buffsize);

		if (strcmp(linebuff, "exit") == 0)
		{
			printf("Exiting the shell\n");
			freenfr(linebuff);
			break;
		}

		argv = putstrtok(linebuff, " ");
        if (argv == NULL)
        {
            perror("argv");
            exit(1);
        }
		fp = MF_fullpath(argv[0]);
		execution(fp, argv, linebuff, environ);
	}
}

void nonInterproc()
{
    char *linebuff = NULL;
    size_t buffsize = 0;
    char **argv;
    char *fp;

    while (getline(&linebuff, &buffsize, stdin) != -1)
    {
        
        if (linebuff == NULL)
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }

       
        linebuff[strlen(linebuff) - 1] = '\0';

        argv = putstrtok(linebuff, " ");
        fp = MF_fullpath(argv[0]);
        execution(fp, argv, linebuff, environ);
        
        
        freeArgs(argv);
    }

    freenfr(linebuff);
}



int main()
{
    int interactive;


	interactive = isatty(fileno(stdin));

	if (interactive)
	{
		interproc();
	}
	else
	{
		nonInterproc();
	}

	return EXIT_SUCCESS;
}
