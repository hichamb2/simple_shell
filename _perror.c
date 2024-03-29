#include "main.h"
/**
 * path_perror - Prints an err message when a command is not found in the PATH.
 * @name: The name of the shell program.
 * @command: The command that was not found.
 * @index: The index of the command in the input.
 */
void path_perror(char *name, char *command, int index)
{
	char *idx = itoa(index);
	char message[] = ": not found\n";

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, message, _strlen(message));
	free(idx), idx = NULL;
}
/**
 * exit_perror - Prints an error message for an illegal exit command.
 * @name: The name of the shell program.
 * @command: The exit command.
 * @index: The index of the command in the input.
 */
void exit_perror(char *name, char *command, int index)
{
	char message[] = ": exit: Illegal number: ";
	char *idx = NULL;

	idx = itoa(index);
	if (idx == NULL)
		return;
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, strlen(idx));
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, "\n", 1);
	free(idx), idx = NULL;
}
