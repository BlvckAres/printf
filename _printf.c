#include "main.h"

void print_buffer(char buffer[], int *buff_ndx);

/**
 * _printf - Printf function
 * @sett: sett.
 * Return: Printed chars.
 */

int _printf(const char *sett, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ndx = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (sett == NULL)
		return (-1);

	va_start(list, sett);

	for (i = 0; sett && sett[i] != '\0'; i++)
	{
		if (sett[i] != '%')
		{
			buffer[buff_ndx++] = sett[i];
			if (buff_ndx == BUFF_SIZE)
				print_buffer(buffer, &buff_ndx);
			/* write(1, &sett[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ndx);
			flags = find_flags(sett, &i);
			width = find_width(sett, &i, list);
			precision = find_precision(sett, &i, list);
			size = find_size(sett, &i);
			++i;
			printed = sort_prnt(sett, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ndx);

	va_end(list);

	return (printed_chars);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ndx: digit at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ndx)
{
	if (*buff_ndx > 0)
		write(1, &buffer[0], *buff_ndx);

	*buff_ndx = 0;
}
