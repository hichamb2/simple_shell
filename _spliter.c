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
	tokens = (char **)malloc(sizeof(char *));
	if (tokens == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, " \t\n");
	while (token)
	{
		tokens = (char **)realloc(tokens, sizeof(char *) * (i + 1));
		if (tokens == NULL)/*check realloc*/
		{
			_printf("ERROR realloc()");
			exit(EXIT_FAILURE);
		}
		tokens[i] = (char *)malloc((strlen(token) + 1) * sizeof(char));
		if (tokens[i] == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		strcpy(tokens[i], token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	tokens = (char **)realloc(tokens, (i + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
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

	if (isatty(0) == 1)
		_printf("#cisfun$");
	ret = getline(&line, &size_line, stdin);
	if (ret == -1)
	{
		free(line), line = NULL;
		return (NULL);
	}
	return (line);
}
