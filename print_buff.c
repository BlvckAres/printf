#include "main.h"

/**
 * print_buf - prints buffer
 * @buff: buffer pointer
 * @ibuf: number of bytes to print
 * Return: number of bytes printed.
 */
int print_buf(char *buff, unsigned int ibuf)
{
	return (write(1, buff, ibuf));
}
