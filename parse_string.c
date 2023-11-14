#include "main.h"

/**
 * parse_function - Receives the main string
 * and all the necessary parameters to
 * print a formated string
 * @format: string containing all desired characters.
 * @function_list: list of all the posible functions.
 * @args: list containing all arguments passed to the program.
 *
 * Return: total number of characters printed
 */

int parse_function(const char *format,
		converter_function function_list[], va_list args)
{
	int i, j, s_val, character_print;

	character_print = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; function_list[j].symbol != NULL; j++)
			{
				if (format[i + 1] ==  function_list[j].symbol[0])
				{
					s_val = function_list[j].f(args);
					if (s_val == -1)
						return (-1);
					character_print += s_val;
					break;
				}
			}
			if (function_list[j].symbol == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					character_print = character_print + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			character_print++;
		}
	}
	return (character_print);
}
