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
	(void)argc;

	while (1)
	{
		line = _getline();
		if (line == NULL)
		{
			if (isatty(0) == 1)
				perror(argv[0]);
			return (0);
		}
		command = _spliter(line);

		if (command == NULL)
			continue;
		_execve(command, argv);
	}
	return (0);
}
