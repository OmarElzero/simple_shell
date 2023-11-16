#include "MFheader.h"
/**
 * putstrtok - func that tokenizes
 * @linebuff: str to be tokenized
 * @d: delim to tokenize by
 * Return: arry of commands on success
*/
char **putstrtok(char *linebuff, char *d)
{
	char **dop = NULL;
	int argc = 0;
	int i = 0;
	char *linebuff_copy;
	char *linebuff_copy1;
	char *token;

	linebuff_copy = strdup(linebuff);
	linebuff_copy1 = strdup(linebuff);
	token = strtok(linebuff_copy, d);
	while (token)
	{
		token = strtok(NULL, d);
		argc++;
	}

	dop = malloc(sizeof(char *) * (argc + 1));

	token = strtok(linebuff_copy1, d);
	while (token)
	{
		dop[i] = strdup(token);
		i++;
		token = strtok(NULL, d);
	}
	dop[i] = NULL;

	freenfr(linebuff_copy);
	freenfr(linebuff_copy1);
	return (dop);
}
