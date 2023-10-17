#include "shell.h"
/**
 * tokenize_input - tokenizes the input
 * @input: the input to tokenize
 * @args: counter
 * Return: nothing
 */

void tokenize_input(char *input, char **args)
{
	char *args[256] = {NULL};
	int index = 0;
	char *token;

	token = _strtok(buf, " \t");
	while (token != NULL && index < 255)
	{
		args[index] = token;
		token = _strtok(NULL, " \t");
		index++;
	}
	args[index] = NULL;
}

