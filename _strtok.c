#include "shell.h"
/**
 * _strtok - a custom function that tokenizes an input
 * @str: string to tokenize
 * @delim: the delimiter
 * Return: tokenizes string
 */

char *_strtok(char *str, const char *delim)
{
	static char *pointer;
	char *start;

	pointer = NULL;

	if (str != NULL)
	{
	pointer = str;
	}
	if (pointer == NULL || *pointer == '\0')
	{
		return (NULL);
	}
	start = pointer;

	while (*pointer != '\0' && strchr(delim, *pointer) == NULL)
	{
	pointer++;
	}
	if (*pointer != '\0')
	{
	*pointer = '\0';
	pointer++;
	}
	else
	{
	pointer = NULL;
	}

	return (start);
}
