#include "shell.h"

/**
 * _execute - execute function
 * @command: command
 * @argv: argv
 * @index: index
 *
 * Return: WEXITSTATUS(status).
 */
int _execute(char **command, char **argv, int index)
{
	char *full_cmd;
	pid_t childpid;
	int status;

	full_cmd = handle_path(command[0]);
	if (full_cmd == NULL)
	{
		error_print(argv[0], command[0], index);
		freeArrayOfStrings(command);
		return (127);
	}
	childpid = fork();
	if (childpid == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			freeArrayOfStrings(command);
		}
	}
	else
	{
		waitpid(childpid, &status, 0);
		freeArrayOfStrings(command);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
