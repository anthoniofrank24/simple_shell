#include "shell.h"
/**
 * we_putstring - prints a string
 * @string: to be printed
 * Return: total_value
 */

int we_putstring(char *string)
{
	int index = 0, total_value = 0;

	if (string)
	{
		while (string[index] != '\0')
		{
			we_putchar(string[index]);

			total_value += 1;

			index++;
		}
	}

	return (total_value);
}
