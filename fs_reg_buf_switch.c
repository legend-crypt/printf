#include "main.h"

/**
 * fs_register - registers and tracks all valid format specifiers
 * @sp: character as an input to check if it is valid specifier
 *
 * Return: bool (true or false)
 */
bool fs_register(char sp)
{
	char format_specifiers[] = {
		'c', 's', 'd', 'b', 'i', 'x', 'X', 'o', 'R', 'u', '\0'
	};
	int i;

	for (i = 0; format_specifiers[i]; i++)
	{
		if (sp == format_specifiers[i])
			return (true);
	}
	return (false);
}

/**
 * fs_buf_switcher - A helper function to aid the gen_fs_buf function
 * @sp: confirmed character as a format specifier
 * @j: index to track each FS struct in the fs_buf
 * @fs_buf: a buffer of FS structs generated in the gen_fs_buf function
 *
 * Return: void
 */

void fs_buf_switcher(char sp, int j, FS *fs_buf)
{
	switch (sp)
	{
		case 'c':
			fs_buf[j].type = 'c';
			fs_buf[j].parser = c_parser;
			break;
		case 's':
			fs_buf[j].type = 's';
			fs_buf[j].parser = s_parser;
			break;
		case 'd':
		case 'i':
			fs_buf[j].type = 'd';
			fs_buf[j].parser = d_parser;
			break;
		case 'b':
			fs_buf[j].type = 'b';
			fs_buf[j].parser = b_parser;
			break;
		case 'x':
			fs_buf[j].type = 'x';
			fs_buf[j].parser = x_parser;
			break;
		case 'X':
			fs_buf[j].type = 'X';
			fs_buf[j].parser = X_parser;
			break;
		case 'o':
			fs_buf[j].type = 'o';
			fs_buf[j].parser = o_parser;
			break;
		/**
		 * case 'r':
		 * fs_buf[j].type = 'r';
		 * fs_buf[j].parser = r_parser;
		 * break;
		 */
		case 'R':
			fs_buf[j].type = 'R';
			fs_buf[j].parser = ROT3_parser;
			break;
		case 'u':
			fs_buf[j].type = 'u';
			fs_buf[j].parser = u_parser;
			break;
	}
}