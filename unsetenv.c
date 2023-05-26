#include "shell.h"
/**
 * _unsetenv- removes an environment variable from list
 * @args: arguments.
 * Return: 0 or -1 on failure.
 */
int _unsetenv(char **args)
{
	int i = 0, flag = 0;
	char *name = args[1];
	size_t name_len = my_strlen(name);

	if (!name) /* invalid name */
	{
		perror("unsetenv");
		return (1);
	}

	while (environ[i] != NULL)
	{
		if (my_strncmp(environ[i], name, name_len) == 0 &&
environ[i][name_len] == '=')
		{
			free(environ[i]);
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 1)
	{
		while (environ[i] != NULL) /* shift the remainder to occupy the space */
		{
			environ[i] = environ[i + 1];
			i++;
		}
		environ[i] = NULL;
		return (1);
	}
	perror("unsetenv");
	return (1);
}
