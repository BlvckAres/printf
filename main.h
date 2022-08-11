#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct typ - Struct op
 *
 * @typ: The sett.
 * @fn: The function associated.
 */
struct typ
{
	char typ;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * arrgdef struct typ typ_t - Struct op
 *
 * @typ: The sett.
 * @fm_t: The function associated.
 */
arrgdef struct typ typ_t;

int _printf(const char *sett, ...);
int sort_prnt(const char *typ, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list arrgs, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int find_flags(const char *sett, int *i);
int find_width(const char *sett, int *i, va_list list);
int find_precision(const char *sett, int *i, va_list list);
int find_size(const char *sett, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list arrgs, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int sort_publsh_chr(char c, char buffer[],
	int flags, int width, int precision, int size);
int publsh_numba(int is_positive, int ndx, char buffer[],
	int flags, int width, int precision, int size);
int publsh_digt(int ndx, char bff[], int flags, int width, int precision,
	int length, char lado, char pluss_c);
int publsh_pointer(char buffer[], int ndx, int length,
	int width, int flags, char lado, char pluss_c, int lado_start);

int publsh_unsgnd(int is_neg, int ndx,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int cnvert_sz_numbr(long int num, int size);
long int cnvert_sz_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
