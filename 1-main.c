#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - PID
 * @argc: not used
 * @argv: lines
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	char **command = NULL;
	int index = 0, stat = 0;
	(void)argc;

	while (1)
	{
		line = _getline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDIN_FILENO, "\n", 1);
			return (stat);
		}
		index++;
		command = _spliter(line);
		if (!command)
			continue;
		printf("from main index bi str %s\n", itoa(index));
		if (is_built_in(command[0]) == 1)
			_builtin(command, argv, &stat, index);
		else
			stat = _execve(command, argv, index);
	}
	return (stat);
}
