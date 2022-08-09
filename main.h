#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

/**
  *struct directives - holds fromat specifiers and their functions.
  *@speci: char.
  *@fspeci: function pointer.
  *
  */
typedef struct directives
{
	char speci;
	int (*fspeci)(va_list, int);
} forms;
void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);


int _putchar(char a);
int _printf(const char *format, ...);
int (*get_function(char c))(va_list, int);
int print_char(va_list, int);
int print_str(va_list, int);
int print_int(va_list, int);
int _putchar_int(int, int);
int print_numbers(unsigned long n, unsigned int base, const char *digits);
unsigned int seek_length(unsigned int, int);
int print_hex(va_list args, int len);
int print_hexi(va_list arg, int len);
int print_unsignd(va_list args, int len);
int print_octa(va_list arg, int len);
int print_rot13(va_list arg, int len);
int pri_bina(va_list args, int len);
int pri_binary(unsigned int, int);
int print_string(va_list args, int len);

#endif
