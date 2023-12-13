#include "shell.h"

/**
 * main - basic shell
 * @argc: argument count
 * @argv: argument list
 * Return: success value
 */
int main(int argc, char **argv)
{
	char **args;
	char *line = malloc(120);
	unsigned long int i = 120;
	int status, buffSize = 16;

	args = malloc(sizeof(char *) * 20);

	(void)argc;

	strcpy(line, "");

	while (1)
	{
		printf("$ ");
		if (getline(&line, &i, stdin) == -1)
		{
			free(line);
			free(args);
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		args = tokenize(line, args, &buffSize);
		if (exec(args[0], args, NULL, &status, argv[0]))
		{
			free(line);
			free(args);
			exit(EXIT_FAILURE);
		}
	}
}
