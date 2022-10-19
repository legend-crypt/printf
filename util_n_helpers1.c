#include "main.h"

/**
 * _strlen - A function that returns length of a string
 * @s: The string to be checked
 * Return: The length of the string
 */

unsigned int _strlen(char *s)
{
	int i = 0;

	for (; s[i]; i++)
		;
	return (i);
}

/**
 * rev - reverse string
 * @s: string
 *
 * Return: void
 */
void rev(char *s)
{
	char start = 0, end = _strlen(s) - 1, temp;

	while (start <= end)
	{
		temp = *(s + start);
		*(s + start) = *(s + end);
		*(s + end) = temp;
		start++;
		end--;
	}
}

/**
 * d_parser_h - decimal parser help
 * @num: number to be printed
 * @pv: place_value
 * @buf: string buffer
 *
 * Return: void
 */
void d_parser_h(int num, int pv, char *buf, bool is_signed)
{
	int digit;

	if (pv == 0)
		return;

	digit = num / pv;

	if (is_signed)
		digit = -digit;

	*buf = 48 + digit;

	if (is_signed)
		digit = -digit;

	d_parser_h(num - (digit * pv), pv / 10, (buf + 1), is_signed);
}

/**
 * base_convert_h - converts bases
 * @num: number to be converted
 * @s: string buffer
 * @base: base number
 * @isUpper: checks if its uppercase (base 16)
 *
 * Return: void
 */
void base_convert_h(unsigned int num, char *s, int base, bool isUpper)
{
	int rem;
	char base16[] = {'A', 'B', 'C', 'D', 'E', 'F'};

	if (num <= 0)
	{
		*s = '\0';
		return;
	}

	switch (base)
	{
		case 2:
			*s = 48 + (num % 2);
			base_convert_h(num /= 2, s + 1, 2, false);
			break;
		case 8:
			*s = 48 + (num % 8);
			base_convert_h(num /= 8, s + 1, 8, false);
			break;
		case 16:
			rem = (num % 16);
			*s = (rem >= 10) ?
					isUpper ?
						base16[rem - 10] : base16[rem - 10] + 32
				: 48 + rem;
			base_convert_h(num /= 16, s + 1, 16, isUpper);
			break;
	}
}

/**
 * parse_string_h - parses strings
 * @args: va_list
 * @reverse: reverses string if true
 *
 * Return: char *
 */
char *parse_string_h(va_list args, bool reverse)
{
	char *str_copy;
	char *str_copy2;
	int i;

	str_copy = va_arg(args, char *);
	str_copy2 = malloc(sizeof(char) * (_strlen(str_copy) + 1));

	if (!str_copy2)
		return (NULL);

	for (i = 0; str_copy[i]; i++)
		str_copy2[i] = str_copy[i];

	str_copy2[i] = '\0';

	if (reverse)
		rev(str_copy2);

	return (str_copy2);
}