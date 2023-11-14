#include "main.h"

/**
 * print_reverse - Calls a function to reverse and print a string.
 * @arg: string argument passed to the function
 *
 * Return: amount of characters printed
 */
int print_reverse(va_list arg)
{
	int i;
	char *str;
	char *ptr;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);

	ptr = string_reverse(str);
	if (ptr == NULL)
		return (-1);

	for (i = 0; ptr[i] != '\0'; i++)
		_putchar(ptr[i]);

	free(ptr);
	return (i);
}

/**
 * rot_13 - Converts string to rot13
 * @strs: strings to convert
 *
 * Return: converted strings
 */
int rot_13(va_list strs)
{
	int i;
	int j;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(strs, char *);
	if (str == NULL)
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j <= 52; j++)
		{
			if (str[i] == s[j])
			{
				_putchar(u[j]);
				break;
			}
		}
		if (j == 53)
			_putchar(str[i]);
	}
	return (i);
}
