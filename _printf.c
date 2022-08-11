/* _putchar */
#include "main.h"

void print_buffer(char buffer[], int *b_index);

/**
 * _printf - Printf function
 * @sett: sett.
 * Return: scrpt chrs.
 */

int _printf(const char *sett, ...)
{
	int y, scrpt = 0, scrpt_chrs = 0;
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
				print_buffer(buffer, &b_index);
			/* write(1, &sett[y], 1);*/
			scrpt_chrs++;
		}
		else
		{
			print_buffer(buffer, &b_index);
			flags = find_flags(sett, &y);
			width = find_width(sett, &y, list);
			precision = find_precision(sett, &y, list);
			size = find_size(sett, &y);
			++y;
			scrpt = sort_print(sett, &y, list, buffer,
				flags, width, precision, size);
			if (scrpt == -1)
				return (-1);
			scrpt_chrs += scrpt;
		}
	}

	print_buffer(buffer, &b_index);

	va_end(list);

	return (scrpt_chrs);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chrs
 * @b_index: indexex at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *b_index)
{
	if (*b_index > 0)
		write(1, &buffer[0], *b_index);

	*b_index = 0;
}
