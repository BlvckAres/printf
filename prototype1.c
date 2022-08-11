/* prototype1 */
#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @args: list a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calc active flags
 * @width: find width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chrs printed.
 */
int print_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int y = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_sz_unsgnd(num, size);

	if (num == 0)
		buffer[y--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[y--] = (num % 10) + '0';
		num /= 10;
	}

	y++;

	return (publish_unsgnd(0, y, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @args: lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calc active flags
 * @width: find width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chrs printed
 */
int print_octal(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_sz_unsgnd(num, size);

	if (num == 0)
		buffer[y--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[y--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[y--] = '0';

	y++;

	return (publish_unsgnd(0, y, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @args: lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calc active flags
 * @width: find width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chrs printed
 */
int print_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @args: lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calc active flags
 * @width: find width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chrs printed
 */
int print_hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @args: lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  calc active flags
 * @flag_ch: calc active flags
 * @width: find width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chrs printed
 */
int print_hexa(va_list args, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int y = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_sz_unsgnd(num, size);

	if (num == 0)
		buffer[y--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[y--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[y--] = flag_ch;
		buffer[y--] = '0';
	}

	y++;

	return (publish_unsgnd(0, y, buffer, flags, width, precision, size));
