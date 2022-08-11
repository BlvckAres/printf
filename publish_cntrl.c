/* print_srter */

#include "main.h"
/**
* manage_writ_chr - Prints a string
* @crs: char types.
* @buffer: Buffer array to handle print
* @flags:  Calculates active flags.
* @width: find width.
* @precision: precision specifier
* @size: Size specifier
* Return: Number of chars printed.
*/
int manage_writ_chr(char crs, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and ladoind at buffer's right */

	int y = 0;
	char lado = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		lado = '0';

	buffer[y++] = crs;
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
/**
* publish_numba - Prints a string
* @is_negative: Lista of arguments
* @idex: char types.
* @buffer: buffer array to handle print
* @flags:  calcs active flags
* @width: find width.
* @precision: precision specifier
* @size: size specifier
* Return: Number of chars printed.
*/
int publish_numba(int is_negative, int idex, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - idex - 1;
	char lado = ' ', plus_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		lado = '0';
	if (is_negative)
		plus_ch = '-';
	else if (flags & F_PLUS)
		plus_ch = '+';
	else if (flags & F_SPACE)
		plus_ch = ' ';

	return (publish_num(idex, buffer, flags, width, precision,
		length, lado, plus_ch));
}

/**
* publish_num - write a number using a bufffer
* @idex: Index at which the number starts on the buffer
* @buffer: buffer
* @flags: Flags
* @width: width
* @prec: precision specifier
* @length: number length
* @lado: Pading char
* @plus_c: plus char
*
* Return: Number of printed chars.
*/
int publish_num(int idex, char buffer[],
	int flags, int width, int prec,
	int length, char lado, char plus_c)
{
	int y, lado_start = 1;

	if (prec == 0 && idex == BUFF_SIZE - 2 && buffer[idex] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && idex == BUFF_SIZE - 2 && buffer[idex] == '0')
		buffer[idex] = lado = ' '; /* width is displayed with ladoing ' ' */
	if (prec > 0 && prec < length)
		lado = ' ';
	while (prec > length)
		buffer[--idex] = '0', length++;
	if (plus_c != 0)
		length++;
	if (width > length)
	{
		for (y = 1; y < width - length + 1; y++)
			buffer[y] = lado;
		buffer[y] = '\0';
		if (flags & F_MINUS && lado == ' ')/* Asign plus char to left of buffer */
		{
			if (plus_c)
				buffer[--idex] = plus_c;
			return (write(1, &buffer[idex], length) + write(1, &buffer[1], y - 1));
		}
		else if (!(flags & F_MINUS) && lado == ' ')/* plus char to left of buff */
		{
			if (plus_c)
				buffer[--idex] = plus_c;
			return (write(1, &buffer[1], y - 1) + write(1, &buffer[idex], length));
		}
		else if (!(flags & F_MINUS) && lado == '0')/* plus char to left of lado*/
		{
			if (plus_c)
				buffer[--lado_start] = plus_c;
			return (write(1, &buffer[lado_start], y - lado_start) +
				write(1, &buffer[idex], length - (1 - lado_start)));
		}
	}
	if (plus_c)
		buffer[--idex] = plus_c;
	return (write(1, &buffer[idex], length));
}

/**
 * publish_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @idex: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int publish_unsgnd(int is_negative, int idex,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - idex - 1, y = 0;
	char lado = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && idex == BUFF_SIZE - 2 && buffer[idex] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		lado = ' ';

	while (precision > length)
	{
		buffer[--idex] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		lado = '0';

	if (width > length)
	{
		for (y = 0; y < width - length; y++)
			buffer[i] = lado;

		buffer[y] = '\0';

		if (flags & F_MINUS) /* Asign plus char to left of buffer [buffer>lado]*/
		{
			return (write(1, &buffer[idex], length) + write(1, &buffer[0], y));
		}
		else /* Asign plus char to left of ladoing [lado>buffer]*/
		{
			return (write(1, &buffer[0], y) + write(1, &buffer[idex], length));
		}
	}

	return (write(1, &buffer[idex], length));
}

/**
 * publish_pointer - write a memory address
 * @buffer: arrays of chars
 * @idex: index at which the number starts in the buffer
 * @length: length of number
 * @width: width specifier
 * @flags: flags specifier
 * @lado: char representing the ladoing
 * @plus_c: char representing plus char
 * @lado_start: index at which ladoing should start
 *
 * Return: Number of written chars.
 */
int publish_pointer(char buffer[], int idex, int length,
	int width, int flags, char lado, char plus_c, int lado_start)
{
	int y;

	if (width > length)
	{
		for (y = 3; y < width - length + 3; y++)
			buffer[y] = lado;
		buffer[y] = '\0';
		if (flags & F_MINUS && lado == ' ')/* Asign plus char to left of buffer */
		{
			buffer[--idex] = 'x';
			buffer[--idex] = '0';
			if (plus_c)
				buffer[--idex] = plus_c;
			return (write(1, &buffer[idex], length) + write(1, &buffer[3], y - 3));
		}
		else if (!(flags & F_MINUS) && lado == ' ')/* plus char to left of buffer */
		{
			buffer[--idex] = 'x';
			buffer[--idex] = '0';
			if (plus_c)
				buffer[--idex] = plus_c;
			return (write(1, &buffer[3], y - 3) + write(1, &buffer[idex], length));
		}
		else if (!(flags & F_MINUS) && lado == '0')/* plus char to left of lado*/
		{
			if (plus_c)
				buffer[--lado_start] = plus_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[lado_start], y - lado_start) +
				write(1, &buffer[idex], length - (1 - lado_start) - 2));
		}
	}
	buffer[--idex] = 'x';
	buffer[--idex] = '0';
	if (plus_c)
		buffer[--idex] = plus_c;
	return (write(1, &buffer[idex], BUFF_SIZE - idex - 1));
}
