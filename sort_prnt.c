#include "main.h"
/**
 * sort_prnt - Prints an argument based on its type
 * @typ: settted string in which to print the arguments.
 * @list: list of arguments to be printed.
 * @ndx: ndx.
 * @buffer: Buffer array to handle print.
 * @flags: calcs active flags
 * @width: find width.
 * @precision: precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int sort_prnt(const char *typ, int *ndx, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, un_length = 0, printed_chars = -1;
	typ_t typ_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; typ_types[i].typ != '\0'; i++)
		if (typ[*ndx] == typ_types[i].typ)
			return (typ_types[i].fn(list, buffer, flags, width, precision, size));

	if (typ_types[i].typ == '\0')
	{
		if (typ[*ndx] == '\0')
			return (-1);
		un_length += write(1, "%%", 1);
		if (typ[*ndx - 1] == ' ')
			un_length += write(1, " ", 1);
		else if (width)
		{
			--(*ndx);
			while (typ[*ndx] != ' ' && typ[*ndx] != '%')
				--(*ndx);
			if (typ[*ndx] == ' ')
				--(*ndx);
			return (1);
		}
		un_length += write(1, &typ[*ndx], 1);
		return (un_length);
	}
	return (printed_chars);
}
