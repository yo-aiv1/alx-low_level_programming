#include "main.h"
#include <stdlib.h>

/**
 * checks - frees a 2 dimensional array.
 * @gi: multidimensional array of char.
 * @hig: hig of the array.
 *
 * Return: no return
 */
void checks(char **gi, unsigned int hig)
{
	if (gi != NULL && hig != 0)
	{
		for (; hig > 0; hig--)
			free(gi[hig]);
		free(gi[hig]);
		free(gi);
	}
}

/**
 * strtow - splits a string into words.
 * @str: string.
 *
 * Return: pointer of an array of integers
 */
char **strtow(char *str)
{
	char **aout;
	unsigned int c, hig, i, j, a1;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (c = hig = 0; str[c] != '\0'; c++)
		if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			hig++;
	aout = malloc((hig + 1) * sizeof(char *));
	if (aout == NULL || hig == 0)
	{
		free(aout);
		return (NULL);
	}
	for (i = a1 = 0; i < hig; i++)
	{
		for (c = a1; str[c] != '\0'; c++)
		{
			if (str[c] == ' ')
				a1++;
			if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			{
				aout[i] = malloc((c - a1 + 2) * sizeof(char));
				if (aout[i] == NULL)
				{
					checks(aout, i);
					return (NULL);
				}
				break;
			}
		}
		for (j = 0; a1 <= c; a1++, j++)
			aout[i][j] = str[a1];
		aout[i][j] = '\0';
	}
	aout[i] = NULL;
	return (aout);
}
