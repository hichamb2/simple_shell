#include "main.h"
/**
 * get_path - function makes the path from env
 * @command: the command given
 * Return: a full command with path if exist
 */
char *get_path(char *command)/*str hwa "PATH" mn b3d itbdl fi tsks*/
{
	char *env, *full_command, *path;
	struct stat st;
	int i = 0;

	while (command[i])
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
		i++;
	}
	env = get_env("PATH");
	if (!env)
		return (NULL);
	path = strtok(env, ":");
	while (path)
	{
		full_command = malloc(_strlen(path) + _strlen(command) + 2);
		if (full_command == NULL)
		{
			perror("Problem Malloc");
			return (NULL);
		}
		_strcpy(full_command, path);
		_strcat(full_command, "/");
		_strcat(full_command, command);
		if (stat(full_command, &st) == 0)
		{
			free(env);
			return (full_command);
		}
		free(full_command), full_command = NULL;
		path = strtok(NULL, ":");
	}
	free(path), path = NULL;
	return (NULL);
}
/**
 * get_env - function gets the env from environ
 * @str: the path given
 * Return: the path
 */
char *get_env(char *str)
{
	char *key = NULL, *val = NULL, *temp = NULL, *env = NULL;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		temp = _strdup(environ[i]);
		if (!temp)
			return (NULL); /* Memory allocation failure*/
		key = strtok(temp, "=");
		if (key && _strcmp(key, str) == 0)
		{
			val = strtok(NULL, "");
			if (val)
			{
				env = _strdup(val);
				free(temp);
				return (env);
			}
		}
		free(temp);
	}
	return (NULL);
}
