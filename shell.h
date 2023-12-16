
#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

int exec(char *arg[], int *status, char *name, char **paths);
char **tokenize(char *str, char **tok, int *buffSize, char *separator);
int forkRun(char *arg[], int *status, char *name, char *buf);

#endif
