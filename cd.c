#include "shell.h"
#include <limits.h>
/**
 * cd - changes the directory
 * @path: destination directory
 * Return: nothing
 */

void cd(const char *path)
{
	char current_directory[PATH_MAX];
	char *prev_directory;
	char *new_directory;

	if (getcwd(current_directory, sizeof(current_directory)) == NULL)
	{
		perror("getcwd");
		return;
	}

	prev_directory = strdup(current_directory);

	if (path == NULL || strcmp(path, "") == 0)
	{
		path = getenv("HOME");
	}
	else if (strcmp(path, "-") == 0)
	{
		path = getenv("OLDPWD");
	}

	if (chdir(path) == 0)
	{
		setenv("OLDPWD", prev_directory, 1);
		new_directory = getcwd(NULL, 0);
		if (new_directory != NULL)
		{
		setenv("PWD", new_directory, 1);
		free(new_directory);
		}
	}

	free(prev_directory);
}
