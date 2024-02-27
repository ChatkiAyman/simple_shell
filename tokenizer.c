#include "shell.h"

/**
 * split_string - split string
 *@inputString: input string
 *
 * Return: command.
 */
char **split_string(char *inputString)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int count = 0;
	char delimArray[] = " \t\n";
	int i = 0;

	if (inputString == NULL)
		return (NULL);
	tmp = _strdup(inputString);
	token = strtok(tmp, delimArray);
	if (token == NULL)
	{
		free(inputString), inputString = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, delimArray);
	}
	free(tmp), tmp = NULL;
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(inputString), inputString = NULL;
		return (NULL);
	}
	token = strtok(inputString, delimArray);
	while (token)
	{
		command[i] = _strdup(token);
		i++;
		token = strtok(NULL, delimArray);
	}
	command[i] = NULL;
	free(inputString);
	return (command);

}
