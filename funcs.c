#include "main.h"
/**
 * free_array - function tat free array
 * @array: the array wich will be freed
 */
void free_array(char **array)
{
	int i;

	if (array == NULL)
		return;
	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array), array = NULL;
}
/**
 * _execve - function that makes the same of execve
 * @cmd: array that has the commandes
 * @argv: the array of argv in main
 * @index: index of execution command
 * Return: status value of child pid
 */
int _execve(char *cmd[], char **argv, int index)
{
	int stat;
	char *full_command;
	pid_t pid;

	full_command = get_path(cmd[0]);
	if (!full_command)
	{
		path_perror(argv[0], cmd[0], index);
		free_array(cmd);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(full_command, cmd, environ) == -1)
			{
				free(full_command), full_command = NULL;
				free_array(cmd);
			}
		}
		else
		{
			waitpid(pid, &stat, 0);
			free(full_command), full_command = NULL;
			free_array(cmd);
		}
		return (WEXITSTATUS(stat));
	}
}
