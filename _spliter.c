#include "main.h"
/**
 * _spliter - function that splits the str to an array
 * @str: the str wich splited
 * Return: return the array if succed
 */
char **_spliter(char *str)
{
	char *token = NULL, **tokens = NULL;
	int i = 0;

	if (str == NULL)
		return (NULL);
	token = strtok(str, " \t\n");
	if (token == NULL)
	{
		free(str), str = NULL;
		return (NULL);
	}
	while (token)
	{
		tokens = realloc(tokens, (i + 1) * sizeof(char *));
		if (tokens == NULL)/*check realloc*/
		{
			_printf("ERROR realloc()");
			free(token), token = NULL;
			free(str), str = NULL;
			exit(EXIT_FAILURE);
		}
		tokens[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	tokens[i] = NULL;
	free(token), token = NULL;
	free(str), str = NULL;
	return (tokens);
}
/**
 * _getline - function that take line from commande line
 *
 * Return: if succ return the line taken
 *
 */
char *_getline(void)
{
	char *line = NULL;
	size_t size_line = 0;
	int ret = 0;

	if (isatty(0) == 1)/*if we are in terminal (1)*/
		write(1, "hicham($) ", 11);
	ret = getline(&line, &size_line, stdin);
	if (ret == EOF)
	{
		free(line), line = NULL;
		return (NULL);
	}
	return (line);
}
