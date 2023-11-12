#include "MFheader.h"
#include <string.h>

char *_getenv(const char *name)
{
	int i = 0;
	char *varenv = environ[i];

	while (varenv != NULL)
	{
		char *envnm = strtok(strdup(varenv), "=");
		char *value = strtok(NULL, "=");

		if (envnm != NULL && value != NULL && strcmp(envnm, name) == 0)
		{
			char *result = strdup(value);

			free(envnm);
			return (result);
		}

		free(envnm);
		i++;
		varenv = environ[i];
	}

	return (NULL);
}
