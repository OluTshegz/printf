#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
/**
 * _printf - a function that produces output according to a format
 * @format: a character string composed of zero or more directives
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _print_int(const char *format, ...)
{
	va_list custom_args;
	int count = 0;

	va_start(custom_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'd':
					count += _putchar(va_arg(custom_args, int));
					break;
				case 'i':
					count += _putchar(va_arg(custom_args, int));
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		format++;
	}
	va_end(custom_args);
	return (count);
}
