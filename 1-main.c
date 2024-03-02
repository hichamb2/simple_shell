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
	char **command = NULL, **temp = NULL;
	int index = 0, stat = 0;
	(void)argc;

	while (1)
	{
		line = _getline();
		if (line == NULL)
		{
			if (isatty(0) == 1)
				perror(argv[0]);
			return (stat);
		}
		index++;
		if (_strcmp(line, "env") == 0)
		{
			print_array(environ, temp);
			return(stat);
		}
		command = _spliter(line);
		if (!command)
			continue;
		stat = _execve(command, argv, index);
	}
	return (stat);
}
