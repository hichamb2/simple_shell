#include "main.h"
/**
 * *_strcpy - function pointer
 * @dest: first parametre
 * @src: second parametre
 * Return: the *dest is ret
 */
char *_strcpy(char *dest, char *src)
{
	char *ret = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ret);
}
/**
* _atoi - Convert string to an integer.
* @s: Pointer to a character string.
*
* Return: void.
*/

int _atoi(char *s)
{
	int sign;
	unsigned int num;
	char *temp;

	temp = s;
	num = 0;
	sign = 1;
	while (*temp != '\0' && (*temp < '0' || *temp > '9'))
	{
		if (*temp == '-')
			sign *= -1;
		temp++;
	}
	if (*temp != '\0')
	{
		do {
			num = num * 10 + (*temp - '0');
			temp++;
		} while (*temp >= '0' && *temp <= '9');
	}
	return (num * sign);
}
/**
 * _positive - Check if a given string represents a positive number.
 * @str: The string to be checked.
 *
 * Return: 1 if the string represents a positive number, 0 otherwise.
 */
int _positive(char *str)
{
	int i;

	if (!str || *str == '\0')
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
/**
 * _itostr - Converts an integer to a string.
 * @c: The integer to convert.
 *
 * Return: A pointer to the resulting string.
 */
char *_itostr(int c)
{
	char str[20];
	int i = 0;

	if (c == 0)
		str[i++] = '0';
	else
	{
		while (c > 0)
		{
			str[i++] = (c % 10) + '0';
			c /= 10;
		}
	}
	str[i] = '\0';
	_rev_str(str);
	return (_strdup(str));
}
/**
 * _rev_str - the function that print number of characters
 * @s: the parametre
 */
void _rev_str(char *s)
{
	int i = 0, j = 0;
	char ch;

	while (s[i] != '\0')
		i++;
	for (i = i; i != 0; i--)
	{
		for (j = 0; j < (i - 1); j++)
		{
			ch = s[j + 1];
			s[j + 1] = s[j];
			s[j] = ch;
		}
	}
}
