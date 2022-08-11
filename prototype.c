#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calc active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chrs printed
 */
int print_char(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char q = va_arg(args, int);

	return (manage_writ_chr(q, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calc active flags
 * @width: find width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chrs printed
 */
int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, y;
	char *str = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (y = width - length; y > 0; y--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (y = width - length; y > 0; y--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calc active flags
 * @width: find width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chrs printed
 */
int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calc active flags
 * @width: find width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chrs printed
 */
int print_int(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int y = BUFF_SIZE - 2;
	int is_negative = 0;
	long int k = va_arg(args, long int);
	unsigned long int num;

	k = convert_sz_numba(n, size);

	if (k == 0)
		buffer[y--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (k < 0)
	{
		num = (unsigned long int)((-1) * k);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[y--] = (num % 10) + '0';
		num /= 10;
	}

	y++;

	return (publish_numba(is_negative, y, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calc active flags
 * @width: find width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int k, t, y, totals;
	unsigned int a[32];
	int totals;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(args, unsigned int);
	t = 2147483648; /* (2 ^ 31) */
	a[0] = k / t;
	for (y = 1; y < 32; y++)
	{
		t /= 2;
		a[y] = (k / t) % 2;
	}
	for (y = 0, totals = 0, totals = 0; y < 32; y++)
	{
		totals += a[y];
		if (totals || y == 31)
		{
			char z = '0' + a[y];

			write(1, &z, 1);
			totals++;
		}
	}
	return (totals);
}
