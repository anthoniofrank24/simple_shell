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
		char *prompt = "cisfun$ ", *args[256] = {NULL};
		char *command = NULL;

		write(1, prompt, strlen(prompt));
		read = _getline(&buf, &n, stdin);

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

		command = tokenize_input(buf, args);

		if (command != NULL)
		{

			if (command != NULL && strcmp(command, "env") == 0)
			{
				print_environment();
			}
			else
			{
			execute_command(command, args);
			}
		}
	}
	
	free(buf);
	return (0);
}
