#include "MFheader.h"
/**
 * freenfr - func to free none freed
 * @str: string to free
 * No return void func
*/
void freenfr(char *str)
{
	if (str != NULL)
	{
		free(str);

	}
}
/**
 * freearr - func to free array
 * @arrtbf: array to be freed
 * No return void func
*/
void freearr(char **arrtbf)
{
	int i;

	if (arrtbf != NULL && *arrtbf != NULL)
	{
		for (i = 0; arrtbf[i] != NULL; i++)
		{
			freenfr(arrtbf[i]);
		}
		if (*arrtbf != NULL)
		free(*arrtbf);
		*arrtbf = NULL;
	}
}

