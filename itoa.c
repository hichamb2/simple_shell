#include "main.h"

/**
 * itoa - Converts an integer to a string.
 * @num: The integer to convert.
 *
 * Return: A pointer to the resulting string.
 */
char *itoa(int num)
{
	char *str = (char *)malloc(12 * sizeof(char));
	int i = 0, digit, j;
	int isNegative = 0;
	char temp;

	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		isNegative = 1;
		num = -num;
	}
	if (num == 0)
		str[i++] = '0';
	else
	{
		while (num != 0)
		{
			digit = num % 10;
			str[i++] = '0' + digit;
			num /= 10;
		}
	}
	if (isNegative)
		str[i++] = '-';
	str[i] = '\0';
	j = 0;
	if (isNegative)
		j = 1;
	while (j < i - 1)
	{
		temp = str[j];
		str[j] = str[i - 1];
		str[i - 1] = temp;
		j++;
		i--;
	}
return (str);
}
