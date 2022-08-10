#include "main.h"

/****************** PRINT POINTER ******************/
 /**
 * print_pointer - a function that prints the value of a pointer variable
 * @args: list a of arguments
 * @buffer: buffer array to handle print
 * @flags:  calcs active flags
 * @width: returns width
 * @precision: precision spec
 * @size: size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char plus_c = 0, lado = ' ';
	int ind = BUFF_SIZE - 2, length = 2, lado_start = 1; /* length=2, for '0x' */
	unsigned long n_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	n_addrs = (unsigned long)addrs;

	while (n_addrs > 0)
	{
		buffer[ind--] = map_to[n_addrs % 16];
		n_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		lado = '0';
	if (flags & F_PLUS)
		plus_c = '+', length++;
	else if (flags & F_SPACE)
		plus_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[y], BUFF_SIZE - y - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, lado, plus_c, lado_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - prints ascii codes in hexa of non printable chars
 * @args: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calc active flags
 * @width: find width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int y = 0, offset = 0;
	char *str = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[y] != '\0')
	{
		if (is_printable(str[y]))
			buffer[y + offset] = str[y];
		else
			offset += append_hexa_code(str[y], buffer, y + offset);

		y++;
	}

	buffer[y + offset] = '\0';

	return (write(1, buffer, y + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - prints reverse string.
 * @args: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calc active flags
 * @width: find width
 * @precision: precision specification
 * @size: size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int y, sum = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (y = 0; str[y]; y++)
		;

	for (y = y - 1; y >= 0; y--)
	{
		char z = str[y];

		write(1, &z, 1);
		sum++;
	}
	return (sum);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - print a string in rot13.
 * @args: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calc active flags
 * @width: find width
 * @precision: precision specification
 * @size: size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int y, m;
	int sum = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (y = 0; str[y]; y++)
	{
		for (m = 0; in[m]; m++)
		{
			if (in[m] == str[y])
			{
				x = out[m];
				write(1, &x, 1);
				sum++;
				break;
			}
		}
		if (!in[m])
		{
			x = str[y];
			write(1, &x, 1);
			sum++;
		}
	}
	return (sum);
}
