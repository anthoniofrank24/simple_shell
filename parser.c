#include "shell.h"
/**
 * tokenize_input - tokenizes the input
 * @input: the input to tokenize
 * @args: counter
 * Return: nothing
 */

void tokenize_input(char *input, char **args)
{
	char *token;
	int index = 0;

	token = _strtok(input, " :\t\n-");
	while (token != NULL && index < 255)
	{
		args[index] = token;
		token = _strtok(NULL, " :\t\n-");
		index++;
	}
	args[index] = NULL;
}

