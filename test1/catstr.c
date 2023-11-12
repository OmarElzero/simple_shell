#include "MFheader.h"

/**
 * MF_strcat - string concatinate func
 * @dest: string destination of concate
 * @src: string source to be concatinated
 * Return: ptr to final string
 */
char *MF_strcat(char *dest, char *src)
{
	int n;
	int m;

	n = MF_strlen(dest);

			for (m = 0; src[m]; m++)
			{
				dest[n] = src[m];
					n++;
			}
	return (dest);

}

/**
 * MF_strlen - function that print the length of string
 * @s: string char
 *
 * Return: lenght (success)
 */
int MF_strlen(char *s)
{
	int lenght = 0;

		while (*s != '\0')
		{
			lenght = lenght + 1;
			s = s + 1;
		}
		return (lenght);
}
