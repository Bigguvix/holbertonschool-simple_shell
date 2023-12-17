#include "shell.h"

/**
 * prenv - prints env vars
 * env: env vars
 */
void prenv(char **env)
{
	for (; *env; env++)
		printf("%s\n", *env);
}

/**
 * shexit - exits terminal
 * @line: buffer
 * @args: buffer
 * @path: buffer
 * @code: exit code
 */
void shexit(char *line, char **args, char **path, int code)
{
	free(line);
	free(args);
	free(path);
	exit(code);
}
/**
 * main - basic shell
 * @argc: argument count
 * @argv: argument list
 * Return: success value
 */
int main(int argc, char **argv)
{
	char **args, **path;
	char *line = NULL;
	unsigned long int i;
	int status, argsSize = 16, pathSize = 16;

	args = malloc(sizeof(char *) * argsSize);
	path = malloc(sizeof(char *) * pathSize);
	if (!path || !args)
		exit(1);
	tokenize(getenv("PATH"), path, &pathSize, ":");

	(void)argc;


	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		if (getline(&line, &i, stdin) == -1)
			shexit(line, args, path, EXIT_SUCCESS);

		args = tokenize(line, args, &argsSize, " \n\t");
		if (args[0] == NULL)
			continue;
		if (strcmp(args[0], "exit") == 0)
			shexit(line, args, path, EXIT_SUCCESS);
		if (strcmp(args[0], "env") == 0)
		{
			prenv(environ);
			continue;
		}
		if (exec(args, &status, argv[0], path))
			shexit(line, args, path, EXIT_FAILURE);
	}
}
