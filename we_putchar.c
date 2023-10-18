#include "shell.h"
/**
 * we_putchar - prints character
 * @character: to be printed
 * Return: 1 on success
 */

int we_putchar(char character)
{
	return (write(1, &character, 1));
}
