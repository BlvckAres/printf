#include "main.h"
/**
  *print_string - prints the string.
  *@args: list of arguments.
  *@len: number of chars.
  *
  *Description: any char whose ascii code appears between 0 and 127,
  *will be replaced with \x.
  *Return: length of characters printed.
  */
int print_string(va_list args, int len)
{
	int j;

	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	j = 0;
	while (str[j] != '\0')
	{

		if ((str[j] > 0 && str[j] < 32) || str[j] >= 127)
		{
			if (str[j] < 15)
			{
				len += _printf("\\x0");
				len += _printf("%X", str[j]);
				j++;
			}
			else
			{
				len += _printf("\\x");
				len += _printf("%X", str[j]);
			j++;
			}
		}
		else
		{
			len += _putchar(str[j]);
			j++;
		}
	}
	return (len);
}
