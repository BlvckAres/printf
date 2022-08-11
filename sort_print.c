#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @set: settted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @idex: index.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: find width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *set, int *idex, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, scrpt_chars = -1;
	set_t set_args[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; set_args[i].set != '\0'; i++)
		if (set[*idex] == set_args[i].set)
			return (set_args[i].fn(list, buffer, flags, width, precision, size));

	if (set_args[i].set == '\0')
	{
		if (set[*idex] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (set[*idex - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*idex);
			while (set[*idex] != ' ' && set[*idex] != '%')
				--(*idex);
			if (set[*idex] == ' ')
				--(*idex);
			return (1);
		}
		unknow_len += write(1, &set[*idex], 1);
		return (unknow_len);
	}
	return (scrpt_chars);
}
