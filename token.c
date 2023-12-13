#include "shell.h"
#define TOK_SEPARATOR " \n\t"

/**
 * tokenize - takes a string and separates it
 * @str: the string
 * @tok: the token list buffer
 * @buffSize: the size of the list
 *
 * Return: the token list
 */
char **tokenize(char *str, char **tok, int *buffSize)
{
	int  i = 1;

	tok[0] = strtok(str, TOK_SEPARATOR);
	while ((tok[i] = strtok(NULL, TOK_SEPARATOR)))
	{
		i++;
		if (i == *buffSize)
		{
			*buffSize += 16;
			tok = realloc(tok, sizeof(char *) * (*buffSize));
		}
	}
	return (tok);
}
