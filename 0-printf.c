#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _printf - A function that prints to stdout like printf.
 * @format: A string with maybe or not include various arguments passed to the
 * function.
 * Return: length of format string
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char *temp;
	int i = 0, num, rem, bin = 0, mon = 1;

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[++i])
			{
			case 'c':
				putchar((char) va_arg(ap, int));
				break;
			case '%':
				putchar('%');
				break;
			case 's':
				temp = va_arg(ap, char*);
				while (*temp)
					putchar(*temp++);
				break;
			}
			++i;
			continue;
		}
		putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (i);
}
