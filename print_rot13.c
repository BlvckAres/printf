#include "main.h"
/**
  * print_rot13 - print 13th character from the input.
  * @arg: argument list.
  * @len: length.
  *
  * Return: numer of chars printed.
  */
int print_rot13(va_list arg, int len)
{
	int j, post;

	char r1[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";

	char *str = va_arg(arg, char *);

	if (str == NULL)
		return (-1);

	j = 0;
	post = 0;
	while (str[j])
	{
		if ((str[j] >= 'A' && str[j] <= 'Z')
		|| (str[j] >= 'a' && str[j] <= 'z'))
		{
			post = str[j] - 65;
			len += _putchar(r1[post]);
		}
		else
			len += _putchar(str[j]);

		j++;
	}

	return (len);
}
