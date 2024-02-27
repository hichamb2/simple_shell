#include "main.h"
/**
 * free_array - function tat free array
 * @array: the array wich will be freed
 */
void free_array(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array), array = NULL;
}
