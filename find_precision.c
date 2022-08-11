#include "main.h"

/**
 * find_precision - calcs the precision for printing
 * @sett: settted string in which to print the arguments
 * @i: list of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: precision.
 */
int find_precision(const char *sett, int *i, va_list list)
{
	int prset = *i + 1;
	int precision = -1;

	if (sett[prset] != '.')
		return (precision);

	precision = 0;

	for (prset += 1; sett[prset] != '\0'; prset++)
	{
		if (is_digit(sett[prset]))
		{
			precision *= 10;
			precision += sett[prset] - '0';
		}
		else if (sett[prset] == '*')
		{
			prset++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = prset - 1;

	return (precision);
}
