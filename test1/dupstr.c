#include "MFheader.h"

/**
 * MF_strdup - fnction that copy a strg
 * @str: string to be copied
 * Return: fstr on success NULL on failure
 */
char *MF_strdup(char *str)
{
	int i;
	int j;
	char *fstr;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;
	fstr = malloc(sizeof(char) * (i + 1));

	if (fstr == NULL)
	{
		return (NULL);
	}
	else
	{
		for (j = 0; j < i + 1; j++)
			fstr[j] = str[j];
		return (fstr);
	}

}
