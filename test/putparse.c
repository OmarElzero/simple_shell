#include "MFheader.h"
/**
 * putstrtok - Parsing input
 * @linebuff: The input string
 * @d: The diter
 * Return: An array of parsed
 */
char **putstrtok(char *linebuff, char *d)
{
	char **parsed = NULL;
	int argc = 0;
	int i = 0;
	char *linebuff_copy = strdup(linebuff);

	char *token = strtok(linebuff_copy, d);
	while (token)
	{
		token = strtok(NULL, d);
		argc++;
	}

	parsed = malloc(sizeof(char *) * (argc + 1));

	token = strtok(linebuff, d);
	while (token) 
    {
		parsed[i] = strdup(token);
		i++;
		token = strtok(NULL, d);
	}
	parsed[i] = NULL;

	free(linebuff_copy);
	return parsed;
}
