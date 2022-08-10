#include "main.h"

/**
 * find_width - calcs the width for printing
 * @sett: formatted string in which to print the arguments.
 * @y: list of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int find_width(const char *sett, int *y, va_list list)
{
	int preset_i;
	int width = 0;

	for (preset_i = *y + 1; sett[preset_i] != '\0'; preset_i++)
	{
		if (is_numb(sett[preset_i]))
		{
			width *= 10;
			width += sett[preset_i] - '0';
		}
		else if (sett[preset_i] == '*')
		{
			preset_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*y = preset_i - 1;

	return (width);
}
