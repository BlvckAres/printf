#include "main.h"

/**
  *pri_bina - check if argument is unsigned.
  *@args: list of arguments.
  *@len: number of chars printed.
  *
  *Return: len;
  */
int pri_bina(va_list args, int len)
{
	unsigned int n;

	n = va_arg(args, int);
	return (pri_binary(n, len));
}


/**
  * pri_binary - converts an unsigned int to binary.
  * @n: unsigned int to be converted.
  * @len: length of characters printd.
  *
  * Return: length.
  */
int pri_binary(unsigned int n, int len)
{
	/*count chars*/
	if ((n / 2) != 0)
	{
		pri_binary(n / 2, len);
	}

	_putchar((n % 2) + '0');
	len += find_length(n, 2);
	return (len + 1);
}
