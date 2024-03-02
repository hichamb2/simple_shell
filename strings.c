#include "main.h"
/**
 * _strlen - function that retun nul of cart
 * @s: par
 * Return: size
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strcmp - function
 * @s1: 1st par
 * @s2: 2nd par
 * Return: pointer on dest
 */
int _strcmp(char *s1, char *s2)
{
	int i, comp;

	i = 0;
	comp = 0;
	while (comp == 0 && s1[i] != '\0')
	{
		comp = s1[i] - s2[i];
		i++;
	}
		return (comp);
}
/**
 * _strdup - function that returns a copy of the string given as a parameter.
 * @str: the string wich will be duplicated
 * Return: a pointer to a newly allocated space in memory
 */
char *_strdup(char *str)
{
	int len, i;
	char *ptr;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	ptr = (char *)malloc((sizeof(char) * len) + 1);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		ptr[i] = str[i];
	return (ptr);
}
/**
 * *_strcat - the function.
 * @dest: 1st parametre
 * @src: 2nd parametre
 * Return: po,ter to dest
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ret);
}
