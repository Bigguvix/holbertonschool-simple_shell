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
int exec(char *arg[], int *status, char *name, char **paths)
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
	if (*paths == NULL)
	{
		if (buf[0] == '/')
		{
			fprintf(stderr,
				"%s: %s: command not found\n",
				name, arg[0]);
		}
		else
		{
			fprintf(stderr,
				"%s: %s: No such file or directory\n",
				name, arg[0]);
		}
		return (0);
	}
	return (forkRun(arg, status, name, buf));
}

/**
 * forRun - forks and runs program
 * arg: arguments
 * status: return status
 * name: shell name
 * buf: file to execute
 * Return: success
 */
int forkRun(char *arg[], int *status, char *name, char *buf)
{
	switch (fork())
	{
		case -1:
			break;
		case 0:
			if (execve(buf, arg, environ) == -1)
			{
				fprintf(stderr,
					"%s: %s: No such file or directory\n",
					name, arg[0]);
			}
			return (1);
		default:
			wait(status);
	}
	return (0);
}
