#include "shell.h"

/**
 * builtin_checker - builtinchecker
 * @command: command
 * @st: st
 *
 * Return: NULL.
 */
int builtin_checker(char **command, int *st)
{
	char *builtin_cmd[] = {"exit", "env"};

	if (_strcmp(command[0], builtin_cmd[0]) == 0)
		exit_builtin(command, st);
	else if (_strcmp(command[0], builtin_cmd[1]) == 0)
	{
		var_env(command, st);
		return (1);
	}
	return (0);
}
/**
 * exit_builtin - exit builtin
 * @command: command
 * @st: st
 *
 * Return: st.
 */

void exit_builtin(char **command, int *st)
{
	freeArrayOfStrings(command);
	exit(*st);
}

/**
 * var_env - var_env
 * @command: command
 * @st: st
 *
 */
void var_env(char **command, int *st)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	freeArrayOfStrings(command);
	(*st) = 0;
}
