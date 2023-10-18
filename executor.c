#include "shell.h"
/**
 * execute_command - executes the command
 * @command: the command to execute
 * @args: the full path
 * Return: nothing
 */

void execute_command(char *command, char *args[])
{
	int status;
	char *path, *token, *full_command = NULL;
	int executed = 0;

	if (access(command, X_OK) == 0)
	{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		full_command = command;
	
		execve(full_command, args, environ);
		perror("execve");
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		executed = 1;
	}
	}
	else
	{
		path = getenv("PATH");
		token = _strtok(path, ":");

		while (token != NULL)
		{
			full_command = malloc(strlen(token) + 1 + strlen(command)+1);

			if (full_command == NULL)
			{
				perror("malloc");
				exit(1);
			}

			strcpy(full_command, token);
			strcat(full_command, "/");
			strcat(full_command, command);

			if (access(full_command, X_OK	) == 0)
			{
				pid_t pid = fork();
				if(pid == -1)
				{
					perror("fork");
					exit(1);
				}
				else
				{
					waitpid(pid, &status, 0);
					executed = 1;
				}
			}
			free(full_command);
			token = _strtok(NULL, ":");
		}
	}

	if (!executed)
	{
		perror("execve");
	}
}
