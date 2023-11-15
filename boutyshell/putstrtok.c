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

	linebuff_copy = strdup(linebuff);
	char *token = strtok(linebuff_copy, d);
	while (token)
	{
		token = strtok(NULL, d);
		argc++;
	}

	dop = malloc(sizeof(char *) * (argc + 1));

	token = strtok(linebuff, d);
	while (token)
	{
		dop[i] = strdup(token);
		i++;
		token = strtok(NULL, d);
	}
	dop[i] = NULL;

	freenfr(linebuff_copy);
	freenfr(linebuff_copy1);
	freenfr(token);
	return dop;
}
