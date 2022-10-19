#include "main.h"

/**
 * c_parser - parses character format specifier into string
 * @args: va_list
 *
 * Return: char *
 */
char *c_parser(va_list args)
{
	char *s; /* to hold the new string */

	s = malloc(sizeof(char) * 2);
	if (!s)
		return (NULL);

	s[0] = va_arg(args, int);
	s[1] = '\0';
	return (s);
}

/**
 * s_parser - parses string format specifier
 * @args: va_list
 *
 * Return: char *
 */
char *s_parser(va_list args)
{
	return (parse_string_h(args, false));
}


/**
 * d_parser - parses decimal format specifier
 * @args: va_list
 *
 * Return: char *
 */
char *d_parser(va_list args)
{
	char *buf;
	int num, num_cpy;
	int place_value = 1;
	int bytes = 0;
	bool is_signed = false;

	num = va_arg(args, int);
	if (num < 0)
	{
		bytes++;
		is_signed = true;
	}
	num_cpy = num;

	while (d_parser_com_h(num_cpy, is_signed))
	{
		num_cpy /= 10;
		place_value *= 10;
		bytes++;
	}

	buf = malloc(sizeof(char) * (bytes + 1));
	if (!buf)
		return (NULL);
	if (is_signed)
	{
		*(buf) = '-';
		d_parser_h(num, place_value, (buf + 1), is_signed);
	}
	else
		d_parser_h(num, place_value, buf, is_signed);
	return (buf);
}

/**
 * b_parser - parses binary format specifier
 * @args: va_list
 *
 * Return: char *
 */
char *b_parser(va_list args)
{
	char *s;
	unsigned int num;

	num = va_arg(args, unsigned int);
	s = malloc(sizeof(char) * 33);

	if (s == NULL)
		return (NULL);

	base_convert_h(num, s, 2, false);
	rev(s);

	return (s);
}

/**
 * x_parser - parses hexidecimal(x) format specifier
 * @args: va_list
 *
 * Return: char *
 */
char *x_parser(va_list args)
{
	char *s;
	unsigned int num;

	num = va_arg(args, unsigned int);
	s = malloc(sizeof(char) * 33);

	if (s == NULL)
		return (NULL);

	base_convert_h(num, s, 16, false);
	rev(s);

	return (s);
}