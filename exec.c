#include "shell.h"
/**
 * exec - Executes a program.
 * @str: program name
 * @arg: arguments
 * @env: enviroment
 * @status: return status
 * @name: shell name
 *
 * Return: Succes.
 */
int exec(char *str, char *arg[], char *env[], int *status, char *name)
{
	if (fork())
	{
		wait(status);
	}

	else
	{
		if (execve(str, arg, env) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", name);
		}

		return (1);
	}

	return (0);
}
