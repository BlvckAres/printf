#include "main.h"

/**
 * find_size - Calculates the size to cast the argument
 * @sett: settted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int find_size(const char *sett, int *i)
{
	int preset = *i + 1;
	int size = 0;

	if (sett[preset] == 'l')
		size = S_LONG;
	else if (sett[preset] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = preset - 1;
	else
		*i = preset;

	return (size);
}
