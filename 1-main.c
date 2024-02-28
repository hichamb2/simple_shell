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
	char **tokens = NULL;
	(void)argc;

	while (1)
	{
		line = _getline();
		if (line == NULL)
		{
			if (isatty(0) == 1)
				_printf("\n");
			return (0);
		}
		tokens = _spliter(line);
		if (tokens == NULL)
			continue;
		_execve(tokens, argv);
	}
	return (0);
}
