/* utilities */
#include "main.h"

/**
 * is_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa sett code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_numb - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_numb(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 *convert_sz_num - Casts a number to the specified size
 * @digt: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_sz_num(long int digt, int size)
{
	if (size == S_LONG)
		return (digt);
	else if (size == S_SHORT)
		return ((short)digt);

	return ((int)digt);
}

/**
 * convert_sz_unsgnd - Casts a number to the specified size
 * @digt: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_sz_unsgnd(unsigned long int digt, int size)
{
	if (size == S_LONG)
		return (digt);
	else if (size == S_SHORT)
		return ((unsigned short)digt);

	return ((unsigned int)digt);
}
