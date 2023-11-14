#include "MFheader.h"
/**
 * _getline - func that gets the input
 * @linebuff: where the input is stored
 * @buffsize: buffersize
 * Return: void func no return
 *
*/
void _getline(char **linebuff, size_t *buffsize)
{
	ssize_t line = getline(linebuff, buffsize, stdin);

	if (line == -1 || *linebuff == NULL)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	(*linebuff)[line - 1] = '\0';

}
