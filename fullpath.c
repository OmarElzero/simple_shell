#include "MFheader.h"

/**
 * MF_fullpath - function that finds fullpath
 * @flname: file name to the command
 * Return: path on success and null on failure
 */
char *MF_fullpath(char *flname)
{	char *path;
	char *patcp;
	char *getdir;
	char *fpath;
	/**/
	if (access(flname, X_OK) == 0)
		return (strdup(flname));	{
		}
		else
		{
		path = getenv("PATH");
		if (path == NULL)
		{
			perror("getenv");
			return (NULL);	}
		patcp = strdup(path);
		if (patcp == NULL)
			perror("strdup");
		fpath = malloc(MAX_PL);
		if (fpath == NULL)
		{
			perror("malloc");
			freenfr(patcp);
			return (NULL);	}
		getdir = strtok(patcp, ":");
		while (getdir)
		{
			if (strlen(getdir) + 1 + strlen(flname) < MAX_PL)
			{
				strcpy(fpath, getdir);
				strcat(fpath, "/");
				strcat(fpath, flname);
				if (access(fpath, X_OK) == 0)
				{
					freenfr(patcp);
					return (fpath);	}
			}
			getdir = strtok(NULL, ":");	}
	}	freenfr(patcp);
	freenfr(fpath);
	return (NULL);
}
