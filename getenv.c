#include "shell.h"
/**
 * _getenv - get the environ variable
 * @keyvar: variable to search in env
 *
 * Return: PATH variable
 */
char *_getenv(char *keyvar)
{
	char *tmp, *key, *value, *env;
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, keyvar) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}
