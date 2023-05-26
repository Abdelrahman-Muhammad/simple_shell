#include "shell.h"
/**
 * _strtok- breaks a string into a sequence of zero or more nonempty tokens.
 * @str: the string to be parsed.
 * @delim: set of bytes that delimit the tokens in the parsed string.
 * Return: a pointer to a null-terminated string containing the next token.
 */

char *_strtok(char *str, char *delim)
{
	char *token = NULL, *delimpos = NULL;
	static char *next_token;

	if (str != NULL)
		next_token = str;
	else if (!next_token || *next_token == '\0')
		return (NULL);
	while (my_isspace(*next_token))
		next_token++;
	token = next_token;
	delimpos = _strstr(next_token, delim);
	if (delimpos != NULL)
	{
		*delimpos = '\0';
		next_token = delimpos + my_strlen(delim);
	}
	else
	{
		next_token = NULL;
	}
	if (next_token != NULL && *next_token != '\0')
	{
		while (my_isspace(*next_token))
			next_token++;
	}
		return (token);
}

/**
 * _strstr- searches for string needle from haystack.
 * @haystack: string to search from.
 * @needle: string to search for.
 *Return: pointer to the begining of the found string or NULL.
 */
char *_strstr(char *haystack, char *needle)
{
	char *n = needle;
	char *h = haystack;
	int i = 0, j = 0;

	if (*n == '\0')
		return (h);
	while (h[i] != '\0')
	{
		j = 0;
		while (n[j] != '\0')
		{
			if (h[i + j] != n[j])
				break;
			j++;
		}
		if (n[j] == '\0')
			return ((char *)(h + i));
		i++;
	}
	return (NULL);
}
