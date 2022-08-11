#include "main.h"

/**
 * find_width - calcs the width for printing
 * @sett: settted string in which to print the arguments.
 * @i: list of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int find_width(const char *sett, int *i, va_list list)
{
	int prset;
	int width = 0;

	for (prset = *i + 1; sett[prset] != '\0'; prset++)
	{
		if (is_digit(sett[prset]))
		{
			width *= 10;
			width += sett[prset] - '0';
		}
		else if (sett[prset] == '*')
		{
			prset++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = prset - 1;

	return (width);
}
