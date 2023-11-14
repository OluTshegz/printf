#include "main.h"
#include <stdio.h>

/**
 * string_reverse - reverses a string
 * @s: string to reverse
 *
 * Return: a pointer to a character
 */

char *string_reverse(char *s)
{
	int i;
	int head;
	char temp;
	char *dest;

	for (i = 0; s[i] != '\0'; i++)
	{}

	dest = malloc((sizeof(char) * i) + 1);
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, i);
	for (head = 0; head < i; head++, i++)
	{
		temp = dest[i - 1];
		dest[i - 1] = dest[head];
		dest[head] = temp;
	}
	return (dest);
}

/**
 * base_print - sends characters to be written on standard output
 * @str: string to parse
 *
 * Return: void
 */

void base_print(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * base_length - calculates the length of number
 * @num: number whose length is calculated
 * @base: base to be calculated by/base number to be changed to
 *
 * Return: integer number representing length
 */

unsigned int base_length(unsigned int num, int base)
{
	unsigned int len;

	for (len = 0; num > 0; len++)
		num = num / base;

	return (len);
}

/**
 * _memcpy - copy memory area
 * @dest: copy destination
 * @src: copy source
 * @n: number of bytes to copy
 *
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
