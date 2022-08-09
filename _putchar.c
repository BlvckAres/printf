#include <unistd.h>
/**
 * _putchar - write to stdout
 * @a: char to be written.
 * *Return: number of chars written.
 */
int _putchar(char a)
{
	return (write(1, &a, 1));
}
