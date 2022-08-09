#include "main.h"

/**
 * handler_buff - concatenates the buffer characters
 * @buff: buffer pointer
 * @c: charcter to concatenate
 * @abuf: index of buffer pointer
 * Return: index of buffer pointer.
 */
unsigned int handler_buff(char *buff, char c, unsigned int abuf)
{
	if (abuf == 1024)
	{
		print_buf(buff, abuf);
		abuf = 0;
	}
	buff[abuf] = c;
	abuf++;
	return (abuf);
}
