#include "MFheader.h"
/**
 * MF_fullpath - func to get full path
 * @flname: file name
 * Return: path on success or NUll
 */
char *MF_fullpath(const char *flname)
{
	char *path = getenv("PATH");
	char *patcp = strdup(path);

	char *getdir;
	char *fpath = malloc(MAX_PL);

	getdir = strtok(patcp, ":");

	while (getdir)
	{
		strcpy(fpath, getdir);
		strcat(strcat(fpath, "/"), flname);

		if (access(fpath, X_OK) == 0)
		{
			free(patcp);
			return(fpath);
		}
		getdir = strtok(NULL, ":");
	}

	free(patcp);
	free(fpath);
	return NULL;
}
