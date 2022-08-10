#include "main.h"

void pri_buffer(char buffer[], int *b_index);

/**
 * _printf - printf function
 * @sett: format.
 * Return: Printed chars.
 */

int _printf(const char *sett, ...)
{
	int y, script = 0, script_c = 0;
	int flags, width, precision, size, b_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (sett == NULL)
		return (-1);

	va_start(list, sett);

	for (y = 0; sett && sett[y] != '\0'; y++)
	{
		if (sett[y] != '%')
		{
			buffer[b_index++] = sett[y];
			if (b_index == BUFF_SIZE)
				pri_buffer(buffer, &b_index);
			/* write(1, &sett[y], 1);*/
			script_c++;
		}
		else
		{
			pri_buffer(buffer, &b_index);
			flags = find_flags(sett, &y);
			width = find_width(sett, &y, list);
			precision = find_precision(sett, &y, list);
			size = find_size(sett, &y);
			++y;
			script = handle_print(sett, &y, list, buffer,
				flags, width, precision, size);
			if (script == -1)
				return (-1);
			script_c += script;
		}
	}

	pri_buffer(buffer, &b_index);

	va_end(list);

	return (script_c);
}
/**
 * pri_buffer - prints the contents of the buffer if it exist
 * @buffer: array of chars
 * @b_index: index at which to add next char, represents the length.
 */
void pri_buffer(char buffer[], int *b_index)
{
	if (*b_index > 0)
		write(1, &buffer[0], *b_index);

	*b_index = 0;
}
