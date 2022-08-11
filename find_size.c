#include "main.h"

/**
 * find_size - calcs the size to cast the argument
 * @sett: settted string in which to print the arguments
 * @y: List of arguments to be printed.
 *
 * Return: Precision.
 */
int find_size(const char *sett, int *y)
{
	int preset = *y + 1;
	int size = 0;

	if (sett[preset] == 'l')
		size = S_LONG;
	else if (sett[preset] == 'h')
		size = S_SHORT;

	if (size == 0)
		*y = preset - 1;
	else
		*y = preset;

	return (size);
}
