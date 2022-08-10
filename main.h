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
 * struct set - Struct op
 *
 * @set: The format.
 * @fn: The function associated.
 */
struct set
{
	char set;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct set set_t - Struct op
 *
 * @set: The format.
 * @se_t: The function associated.
 */
typedef struct set set_t;

int _printf(const char *sett, ...);
int print_sort(const char *set, int *ind,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list args, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int find_flags(const char *sett, int *y);
int find_width(const char *sett, int *y, va_list list);
int find_precision(const char *sett, int *y, va_list list);
int find_size(const char *sett, int *y);

/*Function to print string in reverse*/
int print_reverse(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int sort_print_char(char chrs, char buffer[],
	int flags, int width, int precision, int size);
int print_digit(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int print_num(int ind, char bff[], int flags, int width, int precision,
	int length, char lado, char plus_c);
int prints_pointer(char buffer[], int index, int length,
	int width, int flags, char lado, char plus_c, int lado_start);

int write_unsgnd(int is_neg, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** utilities ******************/
int char_print(char);
int append_hexa_code(char, char[], int);
int is_num(char);

long int convert_size_number(long int digt, int size);
long int convert_size_unsgnd(unsigned long int digt, int size);

#endif /* MAIN_H */
