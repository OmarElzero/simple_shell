#include "MFheader.h"

/**
 * main - Entry point of the script
 *
 * Return: 0 on success
 */

int main(void)
{
	char *linebuff = NULL;
	int interactive;


	interactive = isatty(fileno(stdin));

	if (interactive)
	{
		interproc();
	}
	else
	{
		nonInterproc();
	}
	freenfr(linebuff);
	return (EXIT_SUCCESS);
}
