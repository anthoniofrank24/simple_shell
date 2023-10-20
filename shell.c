#include "shell.h"
int mani(void);
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
	int i;

	while (1)
	{
	char *prompt = "", *commands[256], *args[256] = {NULL};

	write(1, prompt, strlen(prompt));
	read = getline(&buf, &n, stdin);
	if (read == -1)
	{
		free(buf);
		exit(0);
	}
	if (buf[read - 1] == '\n')
	{
		buf[read - 1] = '\0';
	}
	handle_exit(buf);

	tokenize_input(buf, commands, ";");

	for (i = 0; commands[i] != NULL; i++)
	{
		tokenize_input(commands[i], args, " \t");
		if (args[0] != NULL)
		{
		if (strcmp(args[0], "env") == 0)
		{
		print_environment();
		}
		else if (strcmp(args[0], "cd") == 0)
		{
			cd(args[1]);
		}
		else
		{
		execute_command(args[0], args);
		}
		}
	}
	}
	free(buf);
	return (0);
}
