#include "shell.h"
/**
 * tokenize_input - tokenizes the input
 * @input: the input to tokenize
 * @args: counter
 * Return: nothing
 */

void tokenize_input(char *input, char **args, char *delimiter)
{
	char *token;
	int index = 0;

	token = strtok(input, delimiter);
	while (token != NULL && index < 255)
	{
		args[index] = token;
		token = strtok(NULL, delimiter);
		index++;
	}
	args[index] = NULL;
}
