#include "main.h"

/**
 * find_precision - Calculates the precision for printing
 * @sett: settted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int find_precision(const char *sett, int *i, va_list list)
{
	int preset = *i + 1;
	int precision = -1;

	if (sett[preset] != '.')
		return (precision);

	precision = 0;

	for (preset += 1; sett[preset] != '\0'; preset++)
	{
		if (is_numb(sett[preset]))
		{
			precision *= 10;
			precision += sett[preset] - '0';
		}
		else if (sett[preset] == '*')
		{
			preset++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = preset - 1;

	return (precision);
}
