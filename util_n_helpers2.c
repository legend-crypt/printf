#include "main.h"

/**
 * u_parser_h - u_parser helper function
 * @num: unsigned number
 * @pv: place_value
 * @buf: character buffer
 *
 * Return: void
 */
void u_parser_h(unsigned int num, unsigned int pv, char *buf)
{
	unsigned int digit;

	if (pv <= 0)
		return;

	digit = num / pv;
	*buf = 48 + digit;

	u_parser_h(num - (digit * pv), pv / 10, (buf + 1));
}

/**
 * d_parser_com_h - d_parser guard and compare function
 * for its while loop which generates the place_value of
 * signed or unsigned input int
 * @num_cpy: copy of the input integer
 * @is_signed: checks if input int is negative or not
 *
 * Return: bool
 */
bool d_parser_com_h(int num_cpy, bool is_signed)
{
	return (is_signed ? num_cpy < -10 : num_cpy > 10);
}