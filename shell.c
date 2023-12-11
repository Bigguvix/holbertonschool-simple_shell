#include "shell.h"

/**
 * main - basic shell
 * @argc: argument count
 * @argv: argument list
 * Return: success value
 */
int main(int argc, char **argv)
{
	char *args[] = {NULL};
	char *line = malloc(120);
	unsigned long int i = 120;
	int status;
	char *p;

	(void)argc;

	strcpy(line, "");

	while (1)
	{
		printf("$ ");
		if (getline(&line, &i, stdin) == -1)
		{
			free(line);
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		if (fork())
		{
			wait(&status);
		}
		else
		{
			p = strchr(line, '\n');
			if (p != NULL)
				*p = '\0';

			if (execve(line, args, NULL) == -1)
			{
				fprintf(stderr,
				"%s: No such file or directory\n", argv[0]);
			}
			exit(EXIT_FAILURE);
		}
	}
}
