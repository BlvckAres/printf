#include "main.h"

/**
  * print_octa - prints octal notation of a number
  * @arg: list of arguments
  * @len: current length of string
  *
  * Return: The length
  */

int print_octa(va_list arg, int len)
{
	unsigned int i = va_arg(arg, unsigned int);

	len += print_numbers(i, 8, "01234567");

	return (len);
}
