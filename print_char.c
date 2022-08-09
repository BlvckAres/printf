#include "main.h"
/**
  * print_char - prints a char to std output
  * @args: list of arguments
  * @len: length of string so far
  *
  * Return: len
  */
int print_char(va_list args, int len)
{
	char c = va_arg(args, int);

	len += _putchar(c);
	return (len);
}


/**
  * print_str - Prints a string to std output
  * @args: List of arguments
  * @len: Length of string so far
  *
  * Return: The new length of the string
  */
int print_str(va_list args, int len)
{
	const char *str = va_arg(args, const char *);

	if (str == NULL)
		str = "(null)";
	while (*str)
		len += _putchar(*str++);

	return (len);
}
