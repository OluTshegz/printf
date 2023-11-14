#include "main.h"
#include <stdio.h>
int check_hex(int, char);

/**
 * print_binary - converts number from base 10 to binary
 * @list: list of arguments
 *
 * Return: length of number printed
 */

int print_binary(va_list list)
{
	unsigned int decimal_num;
	int i, len;
	char *str;
	char *str_rev;

	decimal_num = va_arg(list, unsigned int);
	if (decimal_num == 0)
		return (_putchar('0'));
	if (decimal_num < 1)
		return (-1);

	len = base_length(decimal_num, 2);
	str = malloc((sizeof(char) * len) + 1);
	if (str == NULL)
		return (-1);

	for (i = 0; decimal_num > 0; i++)
	{
		if (decimal_num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		decimal_num /= 2;
	}
	str[i] = '\0';
	str_rev = string_reverse(str);
	if (str_rev == NULL)
		return (-1);

	base_print(str_rev);
	free(str);
	free(str_rev);
	return (len);
}

/**
 * print_octal - prints octal base numeric representation of decimal number
 * @list: list of argument(s)
 *
 * Return: nuumber of symbols printed to standard output
 */

int print_octal(va_list list)
{
	unsigned int num;
	int i;
	char *octal_rep;
	char *str_rev;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);

	i = base_length(num, 8);
	octal_rep = malloc((sizeof(char) * i) + 1);
	if (octal_rep == NULL)
		return (-1);
	for (i = 0; num > 0; i++)
	{
		octal_rep[i] = (num % 8) + 48;
		num /= 8;
	}
	octal_rep[i] = '\0';
	str_rev = string_reverse(octal_rep);
	if (str_rev == NULL)
		return (-1);

	base_print(str_rev);
	free(octal_rep);
	free(str_rev);
	return (i);
}

/**
 * print_hex - prints hexadecimal alpha-numeric
 * representation of decimal number in lowercase
 * @list: list of argument(s)
 *
 * Return: number of characters printed
 */

int print_hex(va_list list)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);

	len = base_length(num, 16);
	hex_rep = malloc(sizeof(char) * len + 1);
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = check_hex(rem_num, 'x');
			hex_rep[len] = rem_num;
		}
		else
			hex_rep[len] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[len] = '\0';
	rev_hex = string_reverse(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	base_print(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}

/**
 * print_HEX - prints hexadecimal alpha-numeric
 * representation of decimal number in uppercase
 * @list: list of argument(s)
 *
 * Return: number of characters printed
 */

int print_HEX(va_list list)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);

	len = base_length(num, 16);
	hex_rep = malloc(sizeof(char) * len + 1);
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = check_hex(rem_num, 'X');
			hex_rep[len] = rem_num;
		}
		else
			hex_rep[len] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[len] = '\0';
	rev_hex = string_reverse(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	base_print(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}

/**
 * check_hex - Checks which hex function is calling it
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */

int check_hex(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
