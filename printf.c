#include "main.h"

/**
 * gen_fs_buf - generates FS buffers based on number of
 * variadic arguments
 * @s: formated string input
 * @n: number of variadic arguments
 *
 * Return: a buffer of FS structs
 */
FS *gen_fs_buf(char *s, int n)
{
	FS *fs_buf;
	int i = 0, j = 0;

	fs_buf = malloc(sizeof(FS) * n);

	if (!fs_buf)
		return (NULL);

	for (; j < n; i++)
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == ' ')
				continue;
			if (fs_register(s[i + 1]))
			{
				fs_buf_switcher(s[i + 1], j, fs_buf);
				j++;
			}
		}
	}

	return (fs_buf);
}

/**
 * str_parser - brings together all functions required to parse
 * and generate an output string
 * @format: format input string
 * @args: va_list
 * @j: pointer to counter that tracks each char of the output string
 *
 * Return: char *
 */
void str_parser(char *format, char *out_str, va_list args, int *j)
{
	FS *fs_buf;
	char *va_arg_str;
	int i = 0, k = 0, l = 0; /* cntrs for format input char, va_arg & its char*/
	bool is_percent_fs = false; /* checks if format specifier is a % */

	fs_buf = gen_fs_buf(format, num_of_vars(format));

	for (; format[i]; i++)
	{
		if (check_fmt_spec((format + i), &is_percent_fs, &i))
		{
			if (is_percent_fs)
			{
				out_str[*j] = '%';
				is_percent_fs = false;
				*j += 1;
			}
			else
			{
				va_arg_str = fs_buf[k].parser(args);
				for (l = 0; va_arg_str[l]; l++)
				{
					out_str[*j] = va_arg_str[l];
					*j += 1;
				}
				free(va_arg_str);
				k++;
			}
		}
		else
		{
			out_str[*j] = format[i];
			*j += 1;
		}
	}
	out_str[*j] = '\0';
	free(fs_buf);
}

/**
 * _printf - prints format string
 * @format: format input string
 *
 * Return: int (number of chars)
 */
int _printf(char *format, ...)
{
	va_list args;
	int j = 0; /* output string (out_str) character counter */
	char formated_str[1024];

	va_start(args, format);
	str_parser(format, formated_str, args, &j);
	write(1, formated_str, j);
	va_end(args);

	return (j);
}