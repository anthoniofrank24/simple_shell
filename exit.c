#include "shell.h"
/**
 * handle_exit - handles exit
 * @buf: input by user
 * Return: nothing
 */

void handle_exit(char *buf)
{
	int status = 0;

	if (strcmp(buf, "exit") == 0)
	{
		free(buf);
		exit(status);
	}
	else if (strncmp(buf, "exit ", 5) == 0)
	{
		status = atoi(buf + 5);
		free(buf);
		exit(status);
	}
}
