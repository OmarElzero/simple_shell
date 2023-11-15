#include "MFheader.h"
/**
 * MF_fullpath - function that finds fullpath
 * @flname: file name to the command
 * Return: path on success and null on failure
 */

char *MF_fullpath(char *flname)
{
	char *path;
	char *patcp;
	char *getdir;
	char *fpath;

	if (access(flname, X_OK) == 0)
	{
		return (flname);
	}
	else
	{
	path = getenv("PATH");
	patcp = strdup(path);
	fpath = malloc(MAX_PL);

	getdir = strtok(patcp, ":");

	while (getdir)
	{
		strcpy(fpath, getdir);
		strcat(strcat(fpath, "/"), flname);

		if (access(fpath, X_OK) == 0)
		{
			freenfr(patcp);
			return (fpath);
		}
		getdir = strtok(NULL, ":");
	}
	}

	freenfr(patcp);
	freenfr(fpath);
	return (NULL);
}
