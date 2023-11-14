#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - imitates the printf function
 * @format: string with format specifier
 *
 * Return: number of printed character
 */

int _printf(const char *format, ...)
{
	int character_print;
	converter_function function_list[] = {
		{"c", print_character},
		{"s", print_string},
		{"%", print_percentage},
		{"i", print_integer},
		{"d", print_integer},
		{"r", print_reverse},
		{"b", print_binary},
		{"R", rot_13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{NULL, NULL}
	};
	va_list args;

	if (format == NULL)
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	va_start(args, format);

	character_print = parse_function(format, function_list, args);
	va_end(args);
	return (character_print);
}
