#include "MFheader.h"
/**
 * interproc - fun that proccess the interactive mode
*/
void interproc()
{
	char *linebuff = NULL;
	size_t buffsize = 0;
	char **argv;

	while (1)
	{
		char *fp;
		printf("BoutomrSHELL  :");
		_getline(&linebuff, &buffsize);

		if (strcmp(linebuff, "exit") == 0)
		{
			printf("Exiting the shell\n");
			freenfr(linebuff);
			break;
		}

		argv = putstrtok(linebuff, " ");
		fp = MF_fullpath(argv[0]);
		execution(fp, argv, linebuff, environ);
	}
}
