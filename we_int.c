#include "shell.h"
/**
 * we_int - prints an integer
 * @digitseen: the digit to be printed
 * Return: total value on success
 */


int we_int(int digitseen)
{
	int a_number, total_value = 0;

	if (digitseen == 0)
		return (0);

	a_number = digitseen / 10;

	total_value += 1;

	we_int(a_number);

	we_putchar((digitseen % 10) + '0');

	return (total_value);
}

