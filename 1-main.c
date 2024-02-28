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
	int stat = 0;
	pid_t pid;
	(void)argc;
	(void)argv;

while (1)
{
	line = _getline();
	if (line == NULL)
	{
		if (isatty(0) == 1)
			_printf(" : kina EOF\n");
		exit(EXIT_FAILURE);
	}
	tokens = _spliter(line);
	if (tokens == NULL)
		continue;
	pid = fork();
	if (pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			_printf("kina EXEC...: \n");
			/*free_array(tokens);*/
			exit(EXIT_FAILURE);
		}
		free_array(tokens);
	}
	else
	{
		wait(&stat);
	}
}
	return (0);
}
