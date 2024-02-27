#include <stdio.h>
#include "shell.h"
/**
 * main - unix shell command
 * line interpreter
 * @argv: pointer to arguments passed to prg
 * @ac: number of arguments passed to prg
 * Return: status of the shell
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, index = 0;
	(void) ac;


	do {
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		index++;
		command = split_string(line);

		if (command == NULL)
		{
			continue;
		}
		if (builtin_checker(command, &status) == 0)
			status = _execute(command, argv, index);
	} while (1);


}
