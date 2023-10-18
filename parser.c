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

	token = strtok(input, " \t");
	while (token != NULL && index < 255)
	{
		args[index] = token;
		token = strtok(NULL, " \t");
		index++;
	}
	args[index] = NULL;
}
