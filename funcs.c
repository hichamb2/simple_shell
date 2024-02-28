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
 * Return: status value of child pid
 */
int _execve(char *cmd[], char **argv)
{
	int stat;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			/*free_array(cmd);*/
		}
	}
	else
	{
		waitpid(pid, &stat, 0);
		/*free_array(cmd);*/
	}
	return (WEXITSTATUS(stat));
}
