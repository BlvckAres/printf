#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * sort_print_char - prints a string
 * @chrs: char types.
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags.
 * @width: find width.
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: Number of chars printed.
 */
int sort_print_char(char chrs, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
	int y = 0;
	char lado = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		lado = '0';

	buffer[y++] = chrs;
	buffer[y] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (y = 0; y < width - 1; y++)
			buffer[BUFF_SIZE - y - 2] = lado;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - y - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - y - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * print_digit - prints a string
 * @is_neg: list of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags: calcs active flags
 * @width: find width.
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: Number of chars printed.
 */
int print_digit(int is_neg, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char lado = ' ', plus_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		lado = '0';
	if (is_neg)
		plus_ch = '-';
	else if (flags & F_PLUS)
		plus_ch = '+';
	else if (flags & F_SPACE)
		plus_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, lado, plus_ch));
}

/**
 * prints_num - prints a number using a bufffer
 * @ind: index at which the number starts on the buffer
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @prec: precision specifier
 * @length: number length
 * @lado: Pading char
 * @plus_c: Extra char
 *
 * Return: Number of printed chars.
 */
int print_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char lado, char plus_c)
{
	int y, lado_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = lado = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		lado = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (plus_c != 0)
		length++;
	if (width > length)
	{
		for (y = 1; y < width - length + 1; y++)
			buffer[y] = lado;
		buffer[y] = '\0';
		if (flags & F_MINUS && lado == ' ')/* Asign extra char to left of buffer */
		{
			if (plus_c)
				buffer[--ind] = plus_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], y - 1));
		}
		else if (!(flags & F_MINUS) && lado == ' ')/* extra char to left of buff */
		{
			if (plus_c)
				buffer[--ind] = plus_c;
			return (write(1, &buffer[1], y - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && lado == '0')/* extra char to left of padd */
		{
			if (plus_c)
				buffer[--lado_start] = plus_c;
			return (write(1, &buffer[lado_start], y - lado_start) +
				write(1, &buffer[ind], length - (1 - lado_start)));
		}
	}
	if (plus_c)
		buffer[--ind] = plus_c;
	return (write(1, &buffer[ind], length));
}

/**
 * print_unsgnd - print an unsigned number
 * @is_neg: number indicating if the num is neg
 * @ind: index at which the number starts in the buffer
 * @buffer: array of chars
 * @flags: flags specifiers
 * @width: width specifier
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: number of written chars.
 */
int print_unsgnd(int is_neg, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position y */
	int length = BUFF_SIZE - ind - 1, y = 0;
	char padd = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		lado = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		lado = '0';

	if (width > length)
	{
		for (y = 0; y < width - length; y++)
			buffer[y] = lado;

		buffer[y] = '\0';

		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], y));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], y) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * prints_pointer - prints a pointer
 * @buffer: arrays of chars
 * @index: index at which the number starts in the buffer
 * @length: length of number
 * @width: width specifier
 * @flags: flags specifier
 * @lado: char representing the padding
 * @plus_c: char representing extra char
 * @lado_start: index at which padding should start
 *
 * Return: Number of written chars.
 */
int prints_pointer(char buffer[], int index, int length,
	int width, int flags, char lado, char plus_c, int lado_start)
{
	int y;

	if (width > length)
	{
		for (y = 3; y < width - length + 3; y++)
			buffer[i] = lado;
		buffer[y] = '\0';
		if (flags & F_MINUS && lado == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (plus_c)
				buffer[--index] = plus_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], y - 3));
		}
		else if (!(flags & F_MINUS) && lado == ' ')/* extra char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (plus_c)
				buffer[--index] = plus_c;
			return (write(1, &buffer[3], y - 3) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && lado == '0')/* extra char to left of padd */
		{
			if (plus_c)
				buffer[--lado_start] = plus_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[lado_start], y - lado_start) +
				write(1, &buffer[index], length - (1 - lado_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (plus_c)
		buffer[--index] = plus_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}
