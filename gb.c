#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * exit_perror - Prints an error message for an illegal exit command.
 * @name: The name of the shell program.
 * @index: The index of the command in the input.
 * @message: The error message to be displayed.
 * @command1: The command parameter that caused the error.
 */
void exit_perror(char *name, int index, char *message, char *command1)
{
	char *idx = _itostr(index);

	if (idx == NULL)
		return;
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": exit: ", 8);
	write(STDERR_FILENO, message, _strlen(message));
	if (command1)
	{
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, command1, _strlen(command1));
	}
	write(STDERR_FILENO, "\n", 1);
	free(idx), idx = NULL;
}

/**
 * exit_sh - Exit the shell with a specified exit value.
 * @command: The command passed to exit.
 * @argv: The arguments passed to the exit command.
 * @stat: Pointer to the status indicator.
 * @index: Index of the command.
 */
void exit_sh(char **command, char **argv, int *stat, int index)
{
	int exit_status = *stat;

	if (command[1])
	{
		if (_positive(command[1]))
		{
			exit_status = _atoi(command[1]);
		}
		else
		{
			exit_perror(argv[0], index, "Illegal number", command[1]);
			free_array(command);
			*stat = 2;
			return;
		}
	}
	free_array(command);
	exit(exit_status);
}
