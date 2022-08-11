#include "main.h"
/**
* sort_publsh_chr - Prints a string
* @c: char types.
* @buffer: Buffer array to handle print
* @flags:  calcs active flags.
* @width: find width.
* @precision: precision specifier
* @size: Size specifier
* Return: Number of chars printed.
*/
int sort_publsh_chr(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and ladondx at buffer's right */
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
* publsh_numba - Prints a string
* @is_neg: lista of arguments
* @ndx: char types.
* @buffer: Buffer array to handle print
* @flags:  calcs active flags
* @width: find width.
* @precision: precision specifier
* @size: Size specifier
* Return: Number of chars printed.
*/
int publsh_numba(int is_neg, int ndx, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ndx - 1;
	char lado = ' ', pluss_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		lado = '0';
	if (is_neg)
		pluss_ch = '-';
	else if (flags & F_PLUS)
		pluss_ch = '+';
	else if (flags & F_SPACE)
		pluss_ch = ' ';

	return (publsh_digt(ndx, buffer, flags, width, precision,
		length, lado, pluss_ch));
}

/**
* publsh_digt - Write a number using a bufffer
* @ndx: digit at which the number starts on the buffer
* @buffer: Buffer
* @flags: Flags
* @width: width
* @prec: precision specifier
* @length: Number length
* @lado: Pading char
* @pluss_c: pluss char
*
* Return: Number of printed chars.
*/
int publsh_digt(int ndx, char buffer[],
	int flags, int width, int prec,
	int length, char lado, char pluss_c)
{
	int i, lado_start = 1;

	if (prec == 0 && ndx == BUFF_SIZE - 2 && buffer[ndx] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ndx == BUFF_SIZE - 2 && buffer[ndx] == '0')
		buffer[ndx] = lado = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		lado = ' ';
	while (prec > length)
		buffer[--ndx] = '0', length++;
	if (pluss_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = lado;
		buffer[i] = '\0';
		if (flags & F_MINUS && lado == ' ')/* Asign pluss char to left of buffer */
		{
			if (pluss_c)
				buffer[--ndx] = pluss_c;
			return (write(1, &buffer[ndx], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && lado == ' ')/* pluss char to left of buff */
		{
			if (pluss_c)
				buffer[--ndx] = pluss_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ndx], length));
		}
		else if (!(flags & F_MINUS) && lado == '0')/* pluss char to left of lado */
		{
			if (pluss_c)
				buffer[--lado_start] = pluss_c;
			return (write(1, &buffer[lado_start], i - lado_start) +
				write(1, &buffer[ndx], length - (1 - lado_start)));
		}
	}
	if (pluss_c)
		buffer[--ndx] = pluss_c;
	return (write(1, &buffer[ndx], length));
}

/**
 * publsh_unsgnd - Writes an unsigned number
 * @is_neg: Number ndxicating if the num is negative
 * @ndx: digit at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int publsh_unsgnd(int is_neg, int ndx,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - ndx - 1, i = 0;
	char lado = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (precision == 0 && ndx == BUFF_SIZE - 2 && buffer[ndx] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		lado = ' ';

	while (precision > length)
	{
		buffer[--ndx] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		lado = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = lado;

		buffer[i] = '\0';

		if (flags & F_MINUS) /* Asign pluss char to left of buffer [buffer>lado]*/
		{
			return (write(1, &buffer[ndx], length) + write(1, &buffer[0], i));
		}
		else /* Asign pluss char to left of padding [lado>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ndx], length));
		}
	}

	return (write(1, &buffer[ndx], length));
}

/**
 * publsh_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ndx: digit at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @lado: Char representing the padding
 * @pluss_c: Char representing pluss char
 * @lado_start: digit at which padding should start
 *
 * Return: Number of written chars.
 */
int publsh_pointer(char buffer[], int ndx, int length,
	int width, int flags, char lado, char pluss_c, int lado_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = lado;
		buffer[i] = '\0';
		if (flags & F_MINUS && lado == ' ')/* Asign pluss char to left of buffer */
		{
			buffer[--ndx] = 'x';
			buffer[--ndx] = '0';
			if (pluss_c)
				buffer[--ndx] = pluss_c;
			return (write(1, &buffer[ndx], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && lado == ' ')/* pluss char to left of buffer */
		{
			buffer[--ndx] = 'x';
			buffer[--ndx] = '0';
			if (pluss_c)
				buffer[--ndx] = pluss_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ndx], length));
		}
		else if (!(flags & F_MINUS) && lado == '0')/* pluss char to left of lado */
		{
			if (pluss_c)
				buffer[--lado_start] = pluss_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[lado_start], i - lado_start) +
				write(1, &buffer[ndx], length - (1 - lado_start) - 2));
		}
	}
	buffer[--ndx] = 'x';
	buffer[--ndx] = '0';
	if (pluss_c)
		buffer[--ndx] = pluss_c;
	return (write(1, &buffer[ndx], BUFF_SIZE - ndx - 1));
}
