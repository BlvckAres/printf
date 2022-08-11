#include "main.h"

/**
 * find_size - calcs the size to cast the argument
 * @sett: settted string in which to print the arguments
 * @i: list of arguments to be printed.
 *
 * Return: precision.
 */
int find_size(const char *sett, int *i)
{
	int prset = *i + 1;
	int size = 0;

	if (sett[prset] == 'l')
		size = S_LONG;
	else if (sett[prset] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = prset - 1;
	else
		*i = prset;

	return (size);
}
