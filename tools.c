#include "shell.h"
/**
 * freeArrayOfStrings- array of string
 * @array: pointer
 *
 */
void freeArrayOfStrings(char **array)
{
	int i;

	if (array == NULL)
		return;
	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}
/**
 * intToChar - int to char
 * @num: num
 *
 * Return:_strdup(str) .
 */
char *intToChar(int num)
{
	char str[28], tmp;
	int i = 0, a = 0, z = 0;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (_strdup(str));
	}
	for (i = 0; num > 0; i++)
	{
		str[i] = (char)((num % 10) + '0');
		num = num / 10;
	}
	str[i] = '\0';
	z = i - 1;
	while (z > a)
	{
		tmp = str[a];
		str[a] = str[z];
		str[z] = tmp;
		a++;
		z--;
	}
	return (_strdup(str));
}

/**
 *error_print - print error
 *@name: error name
 *@command: commande
 *@index: indexing
 *
 */
void error_print(char *name, char *command, int index)
{
	char *id;

	id = intToChar(index);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, id, _strlen(id));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
	free(id);
}
