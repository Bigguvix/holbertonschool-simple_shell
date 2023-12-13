#include "shell.h"

/**
 * main - basic shell
 * @argc: argument count
 * @argv: argument list
 * @envp: environment variables
 * Return: success value
 */
int main(int argc, char **argv, char **envp)
{
	char **args, **path;
	char *line = malloc(120);
	unsigned long int i = 120;
	int status, argsSize = 16, pathSize = 16;

	if (!line)
	{
		exit(1);
	}
	args = malloc(sizeof(char *) * argsSize);
	path = malloc(sizeof(char *) * pathSize);
	tokenize(getenv("PATH"), path, &pathSize, ":");

	(void)argc;

	strcpy(line, "");

	while (1)
	{
		printf("$ ");
		if (getline(&line, &i, stdin) == -1)
		{
			free(line);
			free(args);
			free(path);
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		args = tokenize(line, args, &argsSize, " \n\t");
		if (exec(args, envp, &status, argv[0], path))
		{
			free(line);
			free(args);
			free(path);
			exit(EXIT_FAILURE);
		}
	}
}
