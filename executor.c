#include "shell.h"
/**
 * execute_command - executes the command
 * @command: the command to execute
 * @args: the full path
 * Return: nothing
 */

void execute_command(char *command, char **args)
{
	int status;

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		if (command[0] == '/')
		{
			execve(command, args, environ);
		}
		else
		{
			char *path = getenv("PATH");
			char *token = strtok(path, ":");

			while (token != NULL)
			{
				char full_command[256];

				strcpy(full_command, token);
				strcat(full_command, "/");
				strcat(full_command, command);
				execve(full_command, args, environ);
				token = strtok(NULL, ":");
			}
		}
	perror("execve");
	exit(1);
	}
	else
	{

		waitpid(pid, &status, 0);
	}
}

