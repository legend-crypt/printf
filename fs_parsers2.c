#include "main.h"

/**
 * X_parser - parses hexadecimal(X) format specifier
 * @args: va_list
 *
 * Return: char *
 */
char *X_parser(va_list args)
{
	char *s;
	unsigned int num;

	num = va_arg(args, unsigned int);
	s = malloc(sizeof(char) * 33);

	if (s == NULL)
		return (NULL);

	base_convert_h(num, s, 16, true);
	rev(s);

	return (s);
}

/**
 * o_parser - parses octal format specifier
 * @args: va_list
 *
 * Return: char *
 */
char *o_parser(va_list args)
{
	char *s;
	unsigned int num;

	num = va_arg(args, unsigned int);
	s = malloc(sizeof(char) * 33);

	if (s == NULL)
		return (NULL);

	base_convert_h(num, s, 8, true);
	rev(s);

	return (s);
}

/**
 * r_parser - parses reverse string format specifier
 * @args: va_list
 *
 * Return: char *
 */
char *r_parser(va_list args)
{
	return (parse_string_h(args, true));
}


/**
 * ROT3_parser - parses ROT3 format specifier
 * @args: va_list
 *
 * Return: char *
 */
char *ROT3_parser(va_list args)
{
	char *str_copy, *str;
	int i = 0;

	str = va_arg(args, char*);
	str_copy = malloc(sizeof(char) * (_strlen(str) + 1));

	if (!str_copy)
		return (NULL);

	for (; i < str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str_copy[i] = str[i] >= 'A' && str[i] < 'N' ? str[i] + 13 : str[i] - 13;
		if (str[i] >= 'a' && str[i] <= 'z')
			str_copy[i] = str[i] >= 'a' && str[i] < 'n' ? str[i] + 13 : str[i] - 13;
	}

	return (str_copy);
}


/**
 * u_parser - parses unsigned int format specifier
 * @args: va_list
 *
 * Return: char *
 */
char *u_parser(va_list args)
{
	char *buf;
	unsigned int num, num_cpy;
	int place_value = 1;
	int bytes = 0;

	num = va_arg(args, int);
	num_cpy = num;

	while (num_cpy > 10)
	{
		num_cpy /= 10;
		place_value *= 10;
		bytes++;
	}
	buf = malloc(sizeof(char) * (bytes + 1));
	if (!buf)
		return (NULL);
	u_parser_h(num, place_value, buf);

	return (buf);
}