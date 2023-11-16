#include "MFheader.h"
/**
 * execution - func that execute prog
 * @pathname: full path of executable command
 * @argv: arguments vector
 * @linebuff: input string
 * @environ: environment variable
 * no return void func
 */
void execution(char *pathname, char **argv, char *linebuff, char **environ)
{
	pid_t chpid;
	int status;

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
		if (strcmp(pathname, "/bin/ls") == 0)
		{	printf("Executing /bin/ls...\n");
		}
		if (execve(pathname, argv, environ) == -1)
		{	perror("execve");
			fprintf(stderr, "Error executing command: %s\n", argv[0]);
			freenfr(pathname);
			exit(EXIT_FAILURE);
		}
		fprintf(stderr, "Command not found: %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, " exit status %d\n", WEXITSTATUS(status));
}	}
	if (pathname != NULL)
	freenfr(pathname);
}
