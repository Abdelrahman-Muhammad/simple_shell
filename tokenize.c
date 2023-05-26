#include "shell.h"
char **parse(char *buffer, char *delim, char **args, int num_toks);
/**
 * tokenize- tokenize the command entered by user.
 * @buffer: buffer to tokenize.
 * @delim: delimeter.
 * Return: array of tokenized commands.
 */
char **tokenize(char *buffer, char *delim)
{
	int num_toks = 0;
	char *token = NULL, *buf_cp = NULL, **args = NULL;

	buf_cp = my_strdup(buffer);
	if (!buf_cp)
	{
		perror("strdup");
		free(buffer);
		return (NULL);
	}
	token = _strtok(buf_cp, delim);
	while (token)	/* get number of tokens*/
	{
		num_toks++;
		token = _strtok(NULL, delim);
	}
	args = malloc(sizeof(char *) * (num_toks + 1));
	if (!args)
	{
		perror("Error: malloc");
		free(buf_cp);
		free(buffer);
		return (NULL);
	}
	free(buf_cp);
	return (parse(buffer, delim, args, num_toks));
}

/**
 * parse- parses the buffer
 * @buffer: buffer to parse
 * @delim: delimiter
 * @args: array to store tokens
 * @num_toks: number of tokens
 * Return: parsed tokens.
 */

char **parse(char *buffer, char *delim, char **args, int num_toks)
{
	int i = 0;
	char *token = NULL;

	token = _strtok(buffer, delim);
	for (i = 0; i < num_toks && token != NULL; i++)
	{
		args[i] = my_strdup(token);
		if (!args[i])
		{
			while (i > 0)
				free(args[--i]);
			free(args);
			free(buffer);
			return (NULL);
		}
		token = _strtok(NULL, delim);
	}
	args[i] = NULL;
	return (args);
}
