#include "main.h"

/**
 * check_fmt_spec - checks if format input string contains
 * a format specifier
 * @s: format input string
 * @is_percent_fs: checks if format specifier is a %%
 * @i: a pointer to counter that tracks each character of the
 * format input string
 *
 * Return: bool
 */

bool check_fmt_spec(char *s, bool *is_percent_fs, int *i)
{
	int k, l;

	l = 0;
	if (s[0] == '%')
	{
		for (k = 1; s[k]; k++)
		{
			if (s[k] == ' ')
			{
				l++;
				continue;
			}
			if (fs_register(s[k]) || s[k] == '%')
			{
				if (s[k] == '%')
					*is_percent_fs = true;
				*i = *i + l + 1;
				return (true);
			}
			else
				return (false);
		}
	}

	return (false);
}

/**
 * num_of_vars - checks number of variadic arguements based
 * on the number of valid specifiers (except %%) in the format
 * input string
 * @s: format input string
 *
 * Return: int
 */

int num_of_vars(char *s)
{
	/* counter to keep track of each char of format input string */
	int i = 0;
	/* counter to keep track of variadic arguments */
	int j = 0;

	for (; s[i]; i++)
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == ' ')
				continue;
			if (fs_register(s[i + 1]))
				j++;
		}
	}

	return (j);
}