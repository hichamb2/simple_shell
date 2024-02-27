#include "main.h"
/**
 * _printf - the function
 * @format: the str that pass
 * Return: the size of str printed
 */
int _printf(const char *format, ...)
{
	va_list ptr;
	int i, ret = 0;
	char ff, f;

	if (format == NULL)
		return (-1);
	va_start(ptr, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		f = format[i];
		if (f == '%')
		{
			ff = format[i + 1];
			if (ff == 'c' || ff == 's' || ff == 'd' || ff == 'i')
				ret += get_op_func(ff)(ptr);
			else if (ff == '\0')
			{
				return (-1);
			}
			else if (ff == '%')
				ret += write(1, &f, 1);
			else
			{
				ret += write(1, &f, 1);
				ret += write(1, &ff, 1);
			}
			i++;
		}
		else
			ret += write(1, &f, 1);
	}
	va_end(ptr);
	return (ret);
}
/**
 * get_op_func - function
 * @s: the operation
 * Return: an int
 */
int (*get_op_func(char s))(va_list)
{
	op_t ops[] = {{'s', p_list_str}, {'c', p_list_char}, {'i', p_list_num}, {'d', p_list_num}};
	int i = 0;

	while (i <= 4)
	{
		if (s == ops[i].op)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
/**
 * p_list_char - writes the character c to stdout
 * @ptr: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int p_list_char(va_list ptr)
{
	char c = va_arg(ptr, int);

	return (write(1, &c, 1));
}
/**
 * p_list_str - writes the character c to stdout
 * @ptr: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int p_list_str(va_list ptr)
{
	char *str = va_arg(ptr, char *);
	int ret = 0;

	if (str == NULL)
		str = "(null)";
	ret += write(1, str, _strlen(str));
	return (ret);
}
/**
 * p_list_num - writes the character c to stdout
 * @ptr: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int p_list_num(va_list ptr)
{
	int n = va_arg(ptr, int);
	unsigned int num = n, temp, digitCount, divisor, digit, i, j;
	int ret = 0;

	if (n < 0)
	{
		ret += _putchar('-');
		num = -num;
	}
	temp = num;
	digitCount = 1;
	while (temp /= 10)
		digitCount++;
	for (i = 0; i < digitCount; i++)
	{
		divisor = 1;
		for (j = 1; j < digitCount - i; j++)
			divisor *= 10;
		digit = num / divisor;
		ret += _putchar(digit + '0');
		num %= divisor;
	}
	return (ret);
}
