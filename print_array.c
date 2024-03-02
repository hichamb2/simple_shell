#include "main.h"
/**
 * print_array - the function that print array
 * @array: the array
 */
void print_array(char *array[], char *temp[])
{
	int i;

	for (i = 0; array[i]; i++)
		temp[i] = array[i];
	for (i = 0; array[i]; i++)
		_printf("%s\n", temp[i]);
	free_array(temp);
}
