#include "MFheader.h"
/**
 * 
*/
void execution(char *pathname, char **argv, char *linebuff)
{
	if (execve(pathname, argv, environ) == -1)
	{
		perror("execve");
		freearr(argv);
		free(argv);
		free(linebuff);
		free(pathname);
		exit(EXIT_FAILURE);
	}
}
