#include "main.h"

/**
 * char_printable - evaluates if a char is printable
 * @chrs: char to be evaluated.
 *
 * Return: 1 if chrs is printable, 0 otherwise
 */
int char_print(char chrs)
{
	if (chrs >= 32 && chrs < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: array of chars.
 * @y: index at which to start appending.
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
 * is_num - checks if a char is a number
 * @chrs: char to be evaluated
 *
 * Return: 1 if chrs is a digit, 0 otherwise
 */
int is_num(char chrs)
{
	if (chrs >= '0' && chrs <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - casts a number to the specified size
 * @digt: digit to be casted.
 * @size: digit indicating the type to be casted.
 *
 * Return: Casted value of digit
 */
long int convert_size_number(long int digt, int size)
{
	if (size == S_LONG)
		return (digt);
	else if (size == S_SHORT)
		return ((short)digt);

	return ((int)digt);
}

/**
 * convert_size_unsgnd - casts a number to the specified size
 * @digt: digit to be casted
 * @size: digit indicating the type to be casted
 *
 * Return: Casted value of digt
 */
long int convert_size_unsgnd(unsigned long int digt, int size)
{
	if (size == S_LONG)
		return (digt);
	else if (size == S_SHORT)
		return ((unsigned short)digt);

	return ((unsigned int)digt);
}
