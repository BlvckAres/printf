#include "main.h"
/**
* sort_publish_chr - Prints a string
* @c: char args.
* @buffer: Buffer array to handle print
* @flags:  Calculates active flags.
* @width: find width.
* @precision: precision specifier
* @size: Size specifier
* Return: Number of chars printed.
*/
int sort_publish_chr(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and ladoind at buffer's right */
	int i = 0;
	char lado = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		lado = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = lado;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
/**
* write_number - Prints a string
* @is_neg: Lista of arguments
* @idex: char args.
* @buffer: Buffer array to handle print
* @flags:  Calculates active flags
* @width: find width.
* @precision: precision specifier
* @size: Size specifier
* Return: Number of chars printed.
*/
int write_number(int is_neg, int idex, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - idex - 1;
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

	return (write_digt(idex, buffer, flags, width, precision,
		length, lado, plus_ch));
}

/**
* write_digt- Write a number using a bufffer
* @idex: Index at which the number starts on the buffer
* @buffer: Buffer
* @flags: Flags
* @width: width
* @prec: Precision specifier
* @length: Number length
* @lado: Pading char
* @plus_c: plus char
*
* Return: Number of printed chars.
*/
int write_digt(int idex, char buffer[],
	int flags, int width, int prec,
	int length, char lado, char plus_c)
{
	int i, lado_start = 1;

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
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = lado;
		buffer[i] = '\0';
		if (flags & F_MINUS && lado == ' ')/* Asign plus char to left of buffer */
		{
			if (plus_c)
				buffer[--idex] = plus_c;
			return (write(1, &buffer[idex], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && lado == ' ')/* plus char to left of buff */
		{
			if (plus_c)
				buffer[--idex] = plus_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[idex], length));
		}
		else if (!(flags & F_MINUS) && lado == '0')/* plus char to left of lado */
		{
			if (plus_c)
				buffer[--lado_start] = plus_c;
			return (write(1, &buffer[lado_start], i - lado_start) +
				write(1, &buffer[idex], length - (1 - lado_start)));
		}
	}
	if (plus_c)
		buffer[--idex] = plus_c;
	return (write(1, &buffer[idex], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_neg: Number indicating if the digtis negative
 * @idex: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_neg, int idex,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - idex - 1, i = 0;
	char lado = ' ';

	UNUSED(is_neg);
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
		for (i = 0; i < width - length; i++)
			buffer[i] = lado;

		buffer[i] = '\0';

		if (flags & F_MINUS) /* Asign plus char to left of buffer [buffer>lado]*/
		{
			return (write(1, &buffer[idex], length) + write(1, &buffer[0], i));
		}
		else /* Asign plus char to left of ladoing [lado>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[idex], length));
		}
	}

	return (write(1, &buffer[idex], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @idex: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @lado: Char representing the ladoing
 * @plus_c: Char representing plus char
 * @lado_start: Index at which ladoing should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int idex, int length,
	int width, int flags, char lado, char plus_c, int lado_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = lado;
		buffer[i] = '\0';
		if (flags & F_MINUS && lado == ' ')/* Asign plus char to left of buffer */
		{
			buffer[--idex] = 'x';
			buffer[--idex] = '0';
			if (plus_c)
				buffer[--idex] = plus_c;
			return (write(1, &buffer[idex], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && lado == ' ')/* plus char to left of buffer */
		{
			buffer[--idex] = 'x';
			buffer[--idex] = '0';
			if (plus_c)
				buffer[--idex] = plus_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[idex], length));
		}
		else if (!(flags & F_MINUS) && lado == '0')/* plus char to left of lado */
		{
			if (plus_c)
				buffer[--lado_start] = plus_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[lado_start], i - lado_start) +
				write(1, &buffer[idex], length - (1 - lado_start) - 2));
		}
	}
	buffer[--idex] = 'x';
	buffer[--idex] = '0';
	if (plus_c)
		buffer[--idex] = plus_c;
	return (write(1, &buffer[idex], BUFF_SIZE - idex - 1));
}
