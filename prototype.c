#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @arrgs: list a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calcs active flags
 * @width: Width
 * @precision: precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(arrgs, int);

	return (sort_publsh_chr(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @arrgs: list a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calcs active flags
 * @width: find width.
 * @precision: precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(arrgs, char *);

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
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
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
 * @arrgs: lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calcs active flags
 * @width: find width.
 * @precision: precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(arrgs);
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
 * @arrgs: lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calcs active flags
 * @width: find width.
 * @precision: precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(arrgs, long int);
	unsigned long int num;

	n = cnvert_sz_numbr(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (publsh_numba(is_neg, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @arrgs: lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calcs active flags
 * @width: find width.
 * @precision: precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, summ;
	unsigned int a[32];
	int sub_totl;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(arrgs, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, summ = 0, sub_totl = 0; i < 32; i++)
	{
		summ += a[i];
		if (summ || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			sub_totl++;
		}
	}
	return (sub_totl);
}
