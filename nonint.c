#include "MFheader.h"
/**
 * nonInterproc - func that proccess non interactive mode
*/
void nonInterproc(void)
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


	
	}

	freenfr(linebuff);
}
