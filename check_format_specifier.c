#include "main.h"

/**
 * print_character - prints character
 * @args: list of argument(s)
 *
 * Return: amount of character(s) printed
 */

int print_character(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * print_string - prints string
 * @args: list of argument(s)
 *
 * Return: amount of characters/string(s) printed
 */

int print_string(va_list args)
{
	int i;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_percentage - prints percentage symbol
 * @args: list of argument(s)
 *
 * Return: amount of character printed
 */

int print_percentage(__attribute__((unused))va_list args)
{
	_putchar('%');
	return (1);
}

/**
 * print_integer - prints integer
 * @args: list of argument(s)
 *
 * Return: amount of integer printed
 */

int print_integer(va_list args)
{
	int num_len;

	num_len = print_number(args);
	return (num_len);
}

/**
 * unsigned_integer - prints unsigned integer
 * @args: list of argument(s)
 *
 * Return: amount of integer printed
 */

int unsigned_integer(va_list args)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (print_unsigned_integer(num));

	if (num < 1)
		return (-1);
	return (print_unsigned_integer(num));
}
