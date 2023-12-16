#include "shell.h"

/**
 * tokenize - takes a string and separates it
 * @str: the string
 * @tok: the token list buffer
 * @buffSize: the size of the list
 * @separator: separator string
 *
 * Return: the token list
 */
char **tokenize(char *str, char **tok, int *buffSize, char *separator)
{
	int  i = 1;

	tok[0] = strtok(str, separator);
	if (tok[0])
		while ((tok[i] = strtok(NULL, separator)))
		{
			i++;
			if (i == *buffSize)
			{
				*buffSize += 16;
				tok = realloc(tok, sizeof(int *) * (*buffSize));
			}
		}
	return (tok);
}
