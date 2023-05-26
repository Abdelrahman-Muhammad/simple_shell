#include "shell.h"
/**
 * _getenv - function searches the environment list to
 * find the environment variable name
 * @name: variable to search for.
 * Return: returns a pointer to the value
 * in the environment, or NULL if there is no match.
 */

char *_getenv(const char *name)
{
	char **k = environ;
	int i = 0;

	while (k[i])
	{
		if (my_strncmp(k[i], name, my_strlen(name)) == 0
&& k[i][my_strlen(name)] == '=')
			return (&k[i][my_strlen(name) + 1]);
		i++;
	}
	return (NULL);
}
