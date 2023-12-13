#include "shell.h"
/**
 * exec - Executes a program.
 * @arg: arguments
 * @env: enviroment
 * @status: return status
 * @name: shell name
 * @paths: PATH variable in list form
 *
 * Return: Succes.
 */
int exec(char *arg[], char *env[], int *status, char *name, char **paths)
{
	char buf[120];

	strcpy(buf, arg[0]);
	if (access(buf, F_OK) != 0)
		while (*paths != NULL)
		{
			strcpy(buf, *paths);
			strcat(buf, "/");
			strcat(buf, arg[0]);
			if (access(buf, F_OK) == 0)
				break;
			paths++;
		}
	if (paths == NULL)
	{
		fprintf(stderr, "%s: No such file or directory\n", name);
		return (1);
	}


	if (fork())
	{
		wait(status);
	}

	else
	{
		if (execve(buf, arg, env) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", name);
		}

		return (1);
	}

	return (0);
}
