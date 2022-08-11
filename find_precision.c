#include "main.h"

/**
 * find_precision - calcs the precision for printing
 * @sett: formatted string in which to print the arguments
 * @y: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int find_precision(const char *sett, int *y, va_list list)
{
	int preset_i = *y + 1;
	int precision = -1;

	if (sett[preset_i] != '.')
		return (precision);

	precision = 0;

	for (preset_i += 1; sett[preset_i] != '\0'; preset_i++)
	{
		if (is_numb(sett[preset_i]))
		{
			precision *= 10;
			precision += sett[preset_i] - '0';
		}
		else if (sett[preset_i] == '*')
		{
			preset_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*y = preset_i - 1;

	return (precision);
}
