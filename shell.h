
#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int exec(char *str, char * arg[], char * env[], int *status, char *name);
char **tokenize(char *, char **, int *);

#endif
