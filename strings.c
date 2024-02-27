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