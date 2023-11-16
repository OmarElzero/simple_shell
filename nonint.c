#include "MFheader.h"

/**
 * nonInterproc - func that processes non-interactive mode
 */
void nonInterproc(void)
{	char *linebuff = NULL;
	size_t buffsize = 0;
	char **argv;
	char *fp;

	while (1)
	{
		if (getline(&linebuff, &buffsize, stdin) == -1)
		{
			perror("end of file");
			break;
		}

		if (linebuff == NULL)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}

		linebuff[strlen(linebuff) - 1] = '\0';

		argv = putstrtok(linebuff, " ");
		if (argv == NULL)
		{
			perror("putstrtok");
			freenfr(linebuff);
			break;
		}
		fp = MF_fullpath(argv[0]);
		if (fp == NULL)
		{
			perror("MF_fullpath");
			freearr(argv);
			freenfr(linebuff);
			break;
		}
		execution(fp, argv, linebuff, environ);
		freearr(argv);
		freenfr(linebuff);
		freenfr(fp);
	}
}
