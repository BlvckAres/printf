#include "main.h"
/**
 * sort_print - prints an argument based on its type
 * @set: formatted string in which to print the arguments.
 * @list: list of arguments to be printed.
 * @ind: ind.
 * @buffer: buffer array to handle print.
 * @flags: calcs active flags
 * @width: find width.
 * @precision: Precision specification
 * @size: size specifier
 * Return: 1 or 2;
 */
int sort_print(const char *set, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int y, u_length = 0, scrpt_c = -1;
	set_t set_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (y = 0; set_types[y].set != '\0'; y++)
		if (set[*ind] == set_types[y].set)
			return (set_types[y].fn(list, buffer, flags, width, precision, size));

	if (set_types[y].set == '\0')
	{
		if (set[*ind] == '\0')
			return (-1);
		u_length += write(1, "%%", 1);
		if (set[*ind - 1] == ' ')
			u_length += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (set[*ind] != ' ' && set[*ind] != '%')
				--(*ind);
			if (set[*ind] == ' ')
				--(*ind);
			return (1);
		}
		u_length += write(1, &set[*ind], 1);
		return (u_length);
	}
	return (scrpt_c);
}
