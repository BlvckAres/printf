#include "main.h"

/**
 * find_width - calcs the width for printing
 * @sett: settted string in which to print the arguments.
 * @y: list of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int find_width(const char *sett, int *y, va_list list)
{
	int preset;
	int width = 0;

	for (preset = *y + 1; sett[preset] != '\0'; preset++)
	{
		if (is_intiga(sett[preset]))
		{
			width *= 10;
			width += sett[preset] - '0';
		}
		else if (sett[preset] == '*')
		{
			preset++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*y = preset - 1;

	return (width);
}
