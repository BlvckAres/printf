#include "main.h"

/**
 * find_width - Calculates the width for printing
 * @sett: settted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int find_width(const char *sett, int *i, va_list list)
{
	int preset;
	int width = 0;

	for (preset = *i + 1; sett[preset] != '\0'; preset++)
	{
		if (is_numb(sett[preset]))
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

	*i = preset - 1;

	return (width);
}
