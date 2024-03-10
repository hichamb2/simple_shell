#include "main.h"
/**
 * is_built_in - function check if a given command is a built in command.
 * @command: The command to be checked.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int is_built_in(char *command)
{
	int i;
	char *builtin[] = {"exit", "env", "cd", "setenv", NULL};

	for (i = 0; builtin[i] != NULL; i++)
	{
		if (_strcmp(builtin[i], command) == 0)
			return (1);
	}
	return (0);
}
/**
 * _builtin - Execute a built in command.
 * @command: The command to be executed.
 * @argv: The arguments passed to the command.
 * @stat: Pointer to the status indicator.
 * @index: Index of the command.
 */
void _builtin(char **command, char **argv, int *stat, int index)
{
	if (_strcmp(command[0], "exit") == 0)
		exit_sh(command, argv, stat, index);
	else if (_strcmp(command[0], "env") == 0)
		print_env(command, stat);
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
			if (command[1])/*dd*/
				exit_perror(argv[0], command[1], index);/*dd*/
			else/*dd*/
				exit_perror(argv[0], "NULL", index);/*dd*/
			/*exit_perror(argv[0], command[1], index);*/
			free_array(command);
			*stat = 2;
			return;
		}
	}
	free_array(command);
	exit(exit_status);
}
/**
 * print_env - Print the environment variables.
 * @command: The command passed to print the environment.
 * @stat: Pointer to the status indicator.
 */
void print_env(char **command, int *stat)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		_printf("%s\n", environ[i]);
	free_array(command);
	*stat = 0;
}
