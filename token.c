#include "shell.h"
#define TOK_SEPARATOR " \n\t"

/**
 * tokenize - takes a string and separates it
 * @str: the string
 *
 * Return: the token list
 */
char **tokenize(char *str, char **tok)
{
	int  i = 1;

	tok[0] = strtok(str, TOK_SEPARATOR);
	while ((tok[i] = strtok(NULL, TOK_SEPARATOR)))
	{
		i++;
	}
	return (tok);
}
