#include "MFheader.h"

/**
 * interproc - function that processes the interactive mode
 */
void interproc(void)
{
    char *linebuff = NULL;
    size_t buffsize = 0;
    char **argv;

    while (1)
    {
        char *fp;

        printf("BoutomrSHELL  :");
        
        if (!_getline(&linebuff, &buffsize))
        {
            printf("Exiting the shell (end of file)\n");
            freenfr(linebuff);
            break;
        }

        if (strcmp(linebuff, "exit") == 0)
        {
            printf("Exiting the shell\n");
            freenfr(linebuff);
            break;
        }

<<<<<<< HEAD
        if (strcmp(linebuff, "env") == 0)
        {
            char **env = environ;
            while (*env != NULL)
            {
                printf("%s\n", *env);
                env++;
            }
            freenfr(linebuff);
            continue;  
        }

        argv = putstrtok(linebuff, " ");
        fp = MF_fullpath(argv[0]);

        execution(fp, argv, linebuff, environ);
    }
=======
		argv = putstrtok(linebuff, " ");
		fp = MF_fullpath(argv[0]);
		execution(fp, argv, linebuff, environ);
		freearr(argv);/*changed*/
	}
>>>>>>> origin/main
}
