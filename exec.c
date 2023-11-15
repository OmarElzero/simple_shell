#include "MFheader.h"

/**
 * execution - func that execute prog
 * @pathname: full path of executable command
 * @argv: arguments vector
 * @linebuff: input string
 * @environ: environement variable
 * no return void func
 */

void execution(char *pathname, char **argv, char *linebuff, char **environ)
{   pid_t chpid;
	if (pathname == NULL)
	{
		perror("command");
		return;
	}
	chpid = fork();

	if (chpid == -1)
	{
		perror("fork");
		freenfr(linebuff);
		freenfr(pathname);
		exit(EXIT_FAILURE);
	}


	if (chpid == 0)
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

		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, " exit status %d\n", WEXITSTATUS(status));
		}
	}

	freenfr(pathname);
}
