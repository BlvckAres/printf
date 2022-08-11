#include "main.h"

void publsh_buffa(char buffer[], int *b_index);

/**
 * _printf - Printf function
 * @sett: sett.
 * Return: Printed chars.
 */

int _printf(const char *sett, ...)
{
	int i, scrpt = 0, scrpt_chars = 0;
	int flags, width, precision, size, b_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (sett == NULL)
		return (-1);

	va_start(list, sett);

	for (i = 0; sett && sett[i] != '\0'; i++)
	{
		if (sett[i] != '%')
		{
			buffer[b_index++] = sett[i];
			if (b_index == BUFF_SIZE)
				publsh_buffa(buffer, &b_index);
			/* write(1, &sett[i], 1);*/
			scrpt_chars++;
		}
		else
		{
			publsh_buffa(buffer, &b_index);
			flags = find_flags(sett, &i);
			width = find_width(sett, &i, list);
			precision = find_precision(sett, &i, list);
			size = find_size(sett, &i);
			++i;
			scrpt = handle_print(sett, &i, list, buffer,
				flags, width, precision, size);
			if (scrpt == -1)
				return (-1);
			scrpt_chars += scrpt;
		}
	}

	publsh_buffa(buffer, &b_index);

	va_end(list);

	return (scrpt_chars);
}
/**
 * publsh_buffa - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @b_index: Index at which to add next char, represents the length.
 */
void publsh_buffa(char buffer[], int *b_index)
{
	if (*b_index > 0)
		write(1, &buffer[0], *b_index);

	*b_index = 0;
}
