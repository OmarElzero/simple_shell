#include "MFheader.h"

int main()
{
	char *linebuff = NULL;
	size_t buffsize = 0;
	ssize_t line;
    char *pathname;
    pid_t id;
    char **argv;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
		{
			Prompt();
		}
			line = getline(&linebuff, &buffsize, stdin);

		if ((line == -1) && (buffsize=0))
		{
			printf("\n");
			if (linebuff != NULL)
            {
			free(linebuff);
			linebuff = NULL;
			}
			break;
		}

		linebuff[line - 1] = '\0';

		
        argv = putstrtok(linebuff, " ");
    

		if (strcmp(argv[0], "exit") == 0)
		{
			printf("Exiting the shell\n");
			freenfr(linebuff);
			break;
		}
		
            pathname= MF_fullpath(argv[0]);
		if (pathname == NULL) 
		{
            perror("Command not found");
			continue;
        }
		    id = fork();

		if (id == -1)
		{
			perror("fork");
			freenfr(linebuff);
			exit(EXIT_FAILURE);
		}
		else if (id == 0)
		{
			
    	   if (execve(pathname, argv, NULL) == -1)
			{
				perror("execve");
				freenfr(linebuff);
				freenfr(pathname);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);

		}
		freenfr(linebuff);

	}

	return(EXIT_SUCCESS);
}
