#include "MFheader.h"

/**
 * MF_strcmp - str comparing function
 * @s1: first str to compare
 * @s2: second str
 * Return: 0 if similar negative or positive value if deffirent
 */
int MF_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
	if (s1[i] != s2[i])
	{
		return (s1[i] - s2[i]);
	}
		i++;
	}
	return (0);
}
