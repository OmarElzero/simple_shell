#include "MFheader.h"

/**
 * main - Entry point of the script
 *
 * Return: 0 on success
 */

int main(void)
{
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

	return (EXIT_SUCCESS);
}
