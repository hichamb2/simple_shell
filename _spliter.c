#include "main.h"
/**
 * _spliter - function that splits the str to an array
 * @str: the str wich splited
 * Return: return the array if succed
 */
/*char **_spliter(char *str)
{
	char *token = NULL, **tokens = NULL;
	int i = 0;

	if (str == NULL)
		return (NULL);
	token = strtok(str, " \t\n");
	if (token == NULL)
	{
		free(str);
		return (NULL);
	}
	while (token)
	{
		tokens = realloc(tokens, (i + 1) * sizeof(char *));
		if (!tokens)/check realloc*/
		/*{
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
}*/
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
/**
 * _spliter - function that splits the str to an array
 * @str: the str wich splited
 * Return: return the array if succed
 */
char **_spliter(char *str)
{
	char *line = NULL, *temp = NULL;
	char **array = NULL;
	int i;

	if (!str)
		return (NULL);
	temp = strdup(str);

	line = strtok(temp, " \n\t");
	if (line == NULL)
	{
		free(str), str = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	for (i = 1; line != NULL; i++)
		line = strtok(NULL, " \n\t");
	free(temp), temp = NULL;
	array = malloc(sizeof(char *) * (i + 1));
	if (!array)
	{
		free(str), str = NULL;
		_printf("ERROR malloc()");
		return (NULL);
	}
	line = strtok(str, " \n\t");
	for (i = 0; line != NULL; i++)
	{
		array[i] = strdup(line);
		line = strtok(NULL, " \n\t");
	}
	array[i] = NULL;
	free(str), str = NULL;
	free(line), line = NULL;
	return (array);
}
