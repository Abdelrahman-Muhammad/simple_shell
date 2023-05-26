#include "shell.h"

/**
 * USER_LINE_B - ZZZZZZZZZZZZZZZZZZZZZ
 * @lineptr: ZZZZZZZZZZZZZZZZZZZZZ
 * @buffer: ZZZZZZZZZZZZZZZZZZZZZ
 * @n: ZZZZZZZZZZZZZZZZZZZZZ
 * @j: ZZZZZZZZZZZZZZZZZZZZZ
 */
void USER_LINE_B(
		char **lineptr, size_t *n, char *buffer, size_t j)
{

	if (*lineptr == NULL)
	{
		if  (j > BUFFER_SIZE)
			*n = j;

		else
			*n = BUFFER_SIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFFER_SIZE)
			*n = j;
		else
			*n = BUFFER_SIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * BUFFER_GET - ZZZZZZZZZZZZZZZZZZZZZ
 * @lineptr: ZZZZZZZZZZZZZZZZZZZZZ
 * @n: ZZZZZZZZZZZZZZZZZZZZZ
 * @stream: ZZZZZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZ
 */
ssize_t BUFFER_GET(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFFER_SIZE)
			buffer = REELOCK(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	USER_LINE_B(lineptr, n, buffer, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}

/**
 * GET_BUFFER_LN - ZZZZZZZZZZZZZZZZZZZZZ
 * @i_eof: ZZZZZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZ
 */
char *GET_BUFFER_LN(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}

/**
 * DO_BUFF - ZZZZZZZZZZZZZZZZZZZZZ
 * @my_info: ZZZZZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZ
 */
int DO_BUFF(shell_my_info_t *my_info)
{
	int (*builtin)(shell_my_info_t *my_info);

	if (my_info->args[0] == NULL)
		return (1);

	builtin = BULT_FUNC_GT(my_info->args[0]);

	if (builtin != NULL)
		return (builtin(my_info));

	return (DO_COMMA(my_info));
}
