#include "main.h"

/**
 * is_printable - Evaluates if a char is printable
 * @crs: char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char crs)
{
	if (crs >= 32 && crs < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @y: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int y)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[y++] = '\\';
	buffer[y++] = 'x';

	buffer[y++] = map_to[ascii_code / 16];
	buffer[y] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_intiga - Verifies if a char is a digit
 * @crs: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_intiga(char crs)
{
	if (crs >= '0' && crs <= '9')
		return (1);

	return (0);
}

/**
 * convert_sz_numba - casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_sz_numba(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_sz_unsgnd - casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_sz_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
