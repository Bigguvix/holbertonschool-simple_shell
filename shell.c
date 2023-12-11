#include "shell.h"

int main(void)
{
	char *argv[] = {NULL};
	char *line = malloc(120);
	unsigned long int i = 120;
	int status;

	strcpy(line, "");

	while (1)
	{
		printf("$ ");
		if (getline(&line, &i, stdin) == -1)
		{
			free(line);
			printf("\n");
			exit(0);
		}

		if (fork())
		{
			wait(&status);
		}

		else
		{
			char *p = strchr(line, '\n');
			
			if (p != NULL)
			{
			*p = '\0';
			}

			if (execve(line, argv, NULL) == -1)
			{
			printf("bash: No Program\n");
			}

			exit(EXIT_SUCCESS);
		}
	}
}
