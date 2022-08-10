#include "main.h"

/**
 * find_size - calculates the size to cast the args
 * @sett: formatted string in which to print the args
 * @y: list of arguments to be printed.
 *
 * Return: Precision.
 */
int find_size(const char *sett, int *y)
{
	int preset_i = *y + 1;
	int size = 0;

	if (sett[preset_i] == 'l')
		size = S_LONG;
	else if (sett[preset_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*y = preset_i - 1;
	else
		*y = preset_i;

	return (size);
}
