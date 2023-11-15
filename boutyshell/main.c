#include "MFheader.h"
int main()
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

	return EXIT_SUCCESS;
}
