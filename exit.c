#include "shell.h"
/**
 * _exitt - exits the shell with status.
 * @args: arguments
 * Return: exit status.
 */
int _exitt(char **args)
{
	int exit_status = 0;

	if (args[1] == NULL)
		exit(EXIT_SUCCESS);
	exit_status = atoi(args[1]);
	exit(exit_status);
}

/**
 * my_isspace - checs for whitespace character
 * @c: character input
 *
 * Return: 0 always
 */
int my_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
	{
		return (1);
	}
	return (0);
}

/**
 * my_isdigit - check if it is a digit
 * @c: digit input
 *
 *Return: 0 always
 */
int my_isdigit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * my_atoi - a custom function that converts a string to integer
 *@s: input string
 *
 *Return: 0 always
 */
int my_atoi(const char *s)
{
	int sign = 1, i = 0;
	long result = 0;

	if (s == NULL)
		return (0);

	while (my_isspace(s[i]))
	{
		i++;
	}

	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}

	while (my_isdigit(s[i]))
	{
		result = result * 10 + (s[i] - '0');

		if (result * sign > INT_MAX)
		{
			return (INT_MAX);
		}
		if (result * sign < INT_MIN)
		{
			return (INT_MIN);
		}
		i++;

	}
	return ((int)(result * sign));
}
