#include "main.h"

/**
  * print_hex - prints hex notation of a number
  * @args: list of arguments
  * @len: current length of string
  *
  * Return: the length
  */

int print_hex(va_list args, int len)
{
	unsigned int n = va_arg(args, unsigned int);

	len += print_numbers(n, 16, "0123456789abcdef");

	return (len);
}

/**
  * print_hexi - Printd hexes
  * @arg: argument list
  * @len: current lenght of string
  *
  * Return: Length
  */

int print_hexi(va_list arg, int len)
{
	unsigned int n = va_arg(arg, unsigned int);

	len += print_numbers(n, 16, "0123456789ABCDEF");
	return (len);
}
