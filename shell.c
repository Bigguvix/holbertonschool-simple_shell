#include "shell.h"



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
		if (strcmp(line, "exit\n") == 0)
			shexit(line, args, path, EXIT_SUCCESS);
		if (strlen(line) == 1)
			continue;

		args = tokenize(line, args, &argsSize, " \n\t");
		if (exec(args, &status, argv[0], path))
			shexit(line, args, path, EXIT_FAILURE);
	}
}
