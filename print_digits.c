#include "main.h"
/**
  * print_int - prints number to stdoutput
  * @args: list of arguments
  * @len: length of string so far
  *
  * Return: The new length of the string
  */

int print_int(va_list args, int len)
{
	int j;

	j = va_arg(args, int);

	len = _putchar_int(j, len);
	return (len);
}

/**
  * _putchar_int - prints integers
  * @i: number
  * @len: length of string so far
  *
  * Return: The new length of the string
  */
int _putchar_int(int i, int len)
{
	unsigned long numb;

	if (i < 0)
	{
		len += _putchar('-');
		numb = -(unsigned int)n;
	}
	else
	{
		numb = i;
	}
	len += print_numbers(numb, 10, "0123456789");

	return (len);
}

/**
  * print_numbers - Prints numbers according to the specified base
  * @i: Number to print
  * @base: The base to print.
  * @digits: The digits found in this base
  *
  * Return: The length
  */

int print_numbers(unsigned long i, unsigned int base, const char *digits)
{
	if (i >= base)
		print_numbers((i / base), base, digits);
	_putchar(digits[i % base]);
	return (find_length(i, base) + 1);
}

/**
  *seek_length - count length of chars to be printed
  *@i: unsigned int;
  *@base: base of number
  *
  *Return: length;
  */
unsigned int seek_length(unsigned int i, int base)
{
	unsigned int count;

	count = 0;
	while (i > 0)
	{
		i = i / base;
		if (i == 0)
			break;
		count++;
	}
	return (count);
}
