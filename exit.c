#include "shell.h"
/**
 * handle_exit - handles exit
 * @buf: input by user
 * Return: nothing
 */

void handle_exit(char *buf)
{
	int  status = 0;
	char *endptr;
	const char *status_str;

	if (strcmp(buf, "exit") == 0)
	{
		free(buf);
		exit(status);
	}
	else if (strncmp(buf, "exit ", 5) == 0)
	{
		status_str = (buf + 5);
		status = strtol(status_str, &endptr, 0);

		if (*endptr != '\0')
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", status_str);
			free(buf);
			exit(2);
		}
		free(buf);
		exit(status);
	}
}
