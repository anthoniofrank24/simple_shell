#include "shell.h"
/**
 * tokenize_input - tokenizes the input
 * @input: the input to tokenize
 * @args: counter
 * Return: nothing
 */

char *tokenize_input(char *buf, char *args[])
{
	int index = 0;
	char *token = NULL;

	token = _strtok(buf, " \t");
	while (token != NULL && index < 255)
	{
		args[index] = token;
		token = _strtok(NULL, " \t");
		index++;
	}
	args[index] = NULL;

	return (args[0]);
}
