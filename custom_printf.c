#include "custom_main.h"
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
int _printf(const char *format, ...)
{
	va_list custom_args;
	int count = 0;
	char *custom_str;

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
				case 'c':
					count += _putchar(va_arg(custom_args, int));
					break;
				case 's':
					custom_str = va_arg(custom_args, char *);
					if (custom_str == NULL)
						custom_str = "(null)";
					while (*custom_str)
					{
						count += _putchar(*custom_str);
						custom_str++;
					}
					break;
				case '%':
					count += _putchar('%');
					break;
			}
		}
		format++;
	}
	va_end(custom_args);
	return (count);
}
