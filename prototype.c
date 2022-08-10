#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - prints a char
 * @args: list a of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of chars printed
 */
int print_char(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(args, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - prints a string
 * @args: list a of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: find width.
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of chars printed
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
 * print_percent - prints a percent sign
 * @args: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: find width.
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of chars printed
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
 * print_int - print int
 * @args: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: find width.
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of chars printed
 */
int print_int(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int y = BUFF_SIZE - 2;
	int is_negative = 0;
	long int i = va_arg(types, long int);
	unsigned long int num;

	i = convert_size_number(i, size);

	if (i == 0)
		buffer[y--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)i;

	if (i < 0)
	{
		num = (unsigned long int)((-1) * i);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[y--] = (num % 10) + '0';
		num /= 10;
	}

	y++;

	return (write_number(is_negative, y, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - prints an unsigned number
 * @args: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: find width.
 * @precision: precision specification
 * @size: size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int i, t, y, total;
	unsigned int a[32];
	int total;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	i = va_arg(args, unsigned int);
	t = 2147483648; /* (2 ^ 31) */
	a[0] = i / t;
	for (y = 1; y < 32; y++)
	{
		t /= 2;
		a[y] = (i / t) % 2;
	}
	for (y = 0, total = 0, sum = 0; i < 32; i++)
	{
		total += a[y];
		if (total || y == 31)
		{
			char z = '0' + a[y];

			write(1, &z, 1);
			sum++;
		}
	}
	return (sum);
}
