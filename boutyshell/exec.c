#include "MFheader.h"

void execution(char *pathname, char **argv, char *linebuff, char **environ)
{   pid_t chpid;
	if (pathname == NULL)
	{
		perror("command");
		return;
	}

	if ((chpid = fork()) == -1)
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
			fprintf(stderr, "Command failed with exit status %d\n", WEXITSTATUS(status));
		}
	}

	freenfr(pathname);
}
