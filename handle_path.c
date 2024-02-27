#include "shell.h"
/**
 * handle_path - get the command path
 * @command: pointer to command
 *
 * Return: pointer to path of command
 */
char *handle_path(char *command)
{
	char *path_env, *full_cmd, *dir;
	int i;
	struct stat st;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
			{
				return (_strdup(command));
			}
			return (NULL);
		}
	}
	path_env = _getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	dir = strtok(path_env, ":");
	do {
		full_cmd = malloc(_strlen(dir) + _strlen(command) + 2);

		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	} while (dir);
	free(path_env);
	free(full_cmd);
	return (NULL);
}
