#include "shell.h"
/**
 * main - mimics the linux shell
 * @void: argument passed to the main
 * Return: 0 on success
 */

int main(void)
{
	char *buf = NULL;
	size_t n = 0;
	ssize_t read;

	while (1)
	{
	char *token = NULL, *prompt = "cisfun$ ", *args[256] = {NULL};

	write(1, prompt, strlen(prompt));
	read = getline(&buf, &n, stdin);

	if (read == -1)
	{
		perror("getline");
		free(buf);
		exit(1);
	}

	if (buf[read - 1] == '\n')
	{
		buf[read - 1] = '\0';
	}

	if (strcmp(buf, "exit") == 0)
	{
		free(buf);
		exit(0);
	}

	if (token != NULL && strcmp(token, "env") == 0)
	{
		print_environment();
	}

	tokenize_input(buf, args);

	execute_command(args[0], args);
	}
	free(buf);
	return (0);
}

