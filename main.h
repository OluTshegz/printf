#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct convert - defines a structure for symbols and functions
 *
 * @symbol: The operator
 * @f: The associate function
 */

struct convert
{
	char *symbol;
	int (*f)(va_list);
};
typedef struct convert converter_function;

int parse_function(const char *format,
		converter_function function_list[], va_list args);
int _printf(const char *format, ...);
int _putchar(char c);
int print_character(va_list args);
int print_string(va_list args);
int print_percentage(va_list args);
int print_integer(va_list args);
int print_number(va_list args);
int unsigned_integer(va_list args);
int print_binary(va_list list);
int print_reverse(va_list arg);
int rot_13(va_list strs);
int print_octal(va_list list);
int print_hex(va_list list);
int print_HEX(va_list list);
int check_hex(int num, char x);
int print_unsigned_integer(unsigned int d);

unsigned int base_length(unsigned int num, int base);
char *string_reverse(char *s);
void base_print(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif /* _MAIN_H_ */
