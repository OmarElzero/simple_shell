#include "MFheader.h"
/**
 * freenfr - func to free non free str
 *@str: string to be freed
*/
void freenfr(char *str)
{
	if(str != NULL)
	{
		free(str);
		str = NULL;
	}
}

/**
 * freearr - func to free arr
 * @arrtf: array to free
*/
void freearr(char **arrtf)
{	
	int i;

	for (i = 0; arrtf[i] != NULL; i++)
	{
		free(arrtf[i]);
	}
}
