#include "shell.h"

/**
 * printenv - prints all environment variables
 * @args: arguments.
 * Return: nothing.
 */

int printenv(char **args)
{
	char **k = NULL;
	int i = 0;

	(void)args;
	k = environ;
	while (k[i])
	{
		write(STDOUT_FILENO, k[i], my_strlen(k[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}

