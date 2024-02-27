#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>

extern char **environ;

int _execute(char **command, char **argv, int index);
char *read_line(void);

char **split_string(char *inputstring);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

void freeArrayOfStrings(char **array);

char *_getenv(char *keyvar);

char *handle_path(char *command);

void error_print(char *name, char *cmd, int index);
char *intToChar(int num);

int builtin_checker(char **command, int *st);
void exit_builtin(char **command, int *st);
void var_env(char **command, int *st);

#endif
