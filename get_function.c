#include "main.h"

/**
  *get_function - returns pointer to function.
  *@c: character to be used to find pointer function.
  *
  *Return: pointer to function or NULL.
  */

int (*get_function(char c))(va_list, int)
{
	forms specifics[] = {
		{'c', print_char},
		{'s', print_str},
		{'d', print_digits},
		{'i', print_digits},
		{'u', print_unsigned},
		{'o', print_octa},
		{'x', print_hex},
		{'X', print_hexi},
		{'R', print_rot13},
		{'b', print_bina},
		{'S', print_string}
	};

	int i;

	for (i = 0; specifics[i].spec; i++)
	{
		if (c == specifics[i].spec)
		{
			return (specifics[i].fspec);
		}
	}

	return (NULL);
}
