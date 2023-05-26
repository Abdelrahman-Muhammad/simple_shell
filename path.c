#include "shell.h"
/**
 * path_handler- finds the valid path to a command.
 * @argv: command's path to find.
 * Return: valid path or NULL if path not found.
 */
char *path_handler(char **argv)
{
	char *path = NULL, *path_cp = NULL;
	char *token = NULL, *command = NULL;
	int arg_len = my_strlen(argv[0]);
	struct stat st;

	path = _getenv("PATH");
	path_cp = my_strdup(path);
	token = _strtok(path_cp, ":");
	while (token)
	{
		command = malloc(sizeof(char) * (my_strlen(token) + arg_len + 2));
		if (!command)
		{
			free(path_cp);
			return (NULL);
		}
		my_strcpy(command, token);
		my_strcat(command, "/");
		my_strcat(command, argv[0]);
		/*my_strcat(command, "\0");*/

		if (stat(command, &st) == 0)
		{
			free(path_cp);
			return (command);
		}
		free(command);
		token = _strtok(NULL, ":");
	}
	if (stat(argv[0], &st) == 0)
	{
		free(path_cp);
		return (argv[0]);
	}
	free(path_cp);
	return (NULL);
}
