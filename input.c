#include "MFheader.h"

/**
 * _getline - function that gets the input
 * @linebuff: where the input is stored
 * @buffsize: buffersize
 * Return: 1 if successful, 0 if end of file
 */
int _getline(char **linebuff, size_t *buffsize)
{
	ssize_t line = getline(linebuff, buffsize, stdin);

	if (line == -1 || *linebuff == NULL)
	{
	perror("getline");
	exit(EXIT_FAILURE);
	}
	if (line == 0)
	return (0);

	(*linebuff)[line - 1] = '\0';
	return (1);
}
