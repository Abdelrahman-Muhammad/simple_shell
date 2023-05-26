#include "shell.h"

/**
*read_input - get inputs from the user
*
*Return: the buffer that contains user's input
*/

char *read_input()
{
	ssize_t read_char = 0;
	size_t n = 0;
	char *lineptr = NULL;

	signal(SIGINT, signal_handler);
	read_char = _getline(&lineptr, &n, stdin);

	if (read_char == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		free(lineptr);
		exit(EXIT_SUCCESS);
	}
	if (read_char == 1 && lineptr[0] == '\n')
	{
/*		write(STDOUT_FILENO, "\n", 1);*/
		free(lineptr);
		return (NULL);
	}

	if (lineptr[read_char - 1] == '\n')
	{
		lineptr[read_char - 1] = '\0';
	}

	return (lineptr);
}

/**
 *signal_handler - handles the SIGINT signal
 *@signum: variables that handles the SIGINT
 *
 *Return: Nothing
*/

void signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
		fflush(stdout);
	}
}

/**
 *free_args - frees all argument arrays
 *@argv: parsed arguments
 *
 *Return: Nothing
*/

void free_args(char **argv)
{
	int i = 0;

	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}

	free(argv);
}
