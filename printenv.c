#include "shell.h"
/**
 * print_environment - prints the environment
 * Return: nothing
 */

void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		myprinter("%s\n", *env);
		env++;
	}
}
