#include "shell.h"
/**
 * _getline - mimicks the standard libary getline function
 * @lineptr: where the buffer is stored
 * @n: size of buffer
 * @stream: standard input
 * Return: length of the input
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buf = BUFFER_SIZE;
	size_t length = 0;
	int c;
	char *temp;


	if (*lineptr == NULL)
	{
		*lineptr = (char *)malloc(buf);
	if (*lineptr == NULL)
	{
		return (-1);
	}
	*n = buf;
	}

	while (1)
	{
		c = fgetc(stream);

		if (c == EOF || c == '\n')
		{
			break;
		}

		(*lineptr)[length] = (char)c;
		length++;

		if (length == *n - 1)
		{
			*n *= 2;
			temp = (char *)realloc(*lineptr, *n);
		if (temp == NULL)
		{
			free(*lineptr);
			return (-1);
		}
		*lineptr = temp;
		}
	}

	if (length == 0 && c == EOF)
	{
		free(*lineptr);
		return (-1);
	}

	(*lineptr)[length] = '\0';
	return (length);
}
