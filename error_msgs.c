#include "shell.h"

/**
 * cd_error_message - this function concatenates the message for cd ERR
 * @my_info: my_info relevant (directory)
 * @msg: message to print
 * @ERR: output message
 * @ver_str: counter lines
 * Return: ERR message
 */
char *cd_error_message(
		shell_my_info_t *my_info, char *msg, char *ERR, char *ver_str)
{
	char *illegal_flag;

	_strcpy(ERR, my_info->av[0]);
	_strcat(ERR, ": ");
	_strcat(ERR, ver_str);
	_strcat(ERR, ": ");
	_strcat(ERR, my_info->args[0]);
	_strcat(ERR, msg);
	if (my_info->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = my_info->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(ERR, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(ERR, my_info->args[1]);
	}

	_strcat(ERR, "\n");
	_strcat(ERR, "\0");
	return (ERR);
}

/**
 * error_message_get_cd - this function ERR message for cd command in get_cd
 * @my_info: my_info relevant (directory)
 * Return: Error message
 */
char *error_message_get_cd(shell_my_info_t *my_info)
{
	int length, len_id;
	char *ERR, *ver_str, *msg;

	ver_str = INT_STR_CONV(my_info->counter);
	if (my_info->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(my_info->args[1]);
	}

	length = _strlen(my_info->av[0]) + _strlen(my_info->args[0]);
	length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	ERR = malloc(sizeof(char) * (length + 1));

	if (ERR == 0)
	{
		free(ver_str);
		return (NULL);
	}

	ERR = cd_error_message(my_info, msg, ERR, ver_str);

	free(ver_str);

	return (ERR);
}

/**
 * error_message_not_found - generic ERR message for command not found
 * @my_info: my_info relevant (counter, arguments)
 * Return: Error message
 */
char *error_message_not_found(shell_my_info_t *my_info)
{
	int length;
	char *ERR;
	char *ver_str;

	ver_str = INT_STR_CONV(my_info->counter);
	length = _strlen(my_info->av[0]) + _strlen(ver_str);
	length += _strlen(my_info->args[0]) + 16;
	ERR = malloc(sizeof(char) * (length + 1));
	if (ERR == 0)
	{
		free(ERR);
		free(ver_str);
		return (NULL);
	}
	_strcpy(ERR, my_info->av[0]);
	_strcat(ERR, ": ");
	_strcat(ERR, ver_str);
	_strcat(ERR, ": ");
	_strcat(ERR, my_info->args[0]);
	_strcat(ERR, ": not found\n");
	_strcat(ERR, "\0");
	free(ver_str);
	return (ERR);
}

/**
 * error_message_exit_shell - generic ERR message for exit in get_exit
 * @my_info: my_info relevant (counter, arguments)
 * Return: Error message
 */
char *error_message_exit_shell(shell_my_info_t *my_info)
{
	int length;
	char *ERR;
	char *ver_str;

	ver_str = INT_STR_CONV(my_info->counter);
	length = _strlen(my_info->av[0]) + _strlen(ver_str);
	length += _strlen(my_info->args[0]) + _strlen(my_info->args[1]) + 23;
	ERR = malloc(sizeof(char) * (length + 1));
	if (ERR == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(ERR, my_info->av[0]);
	_strcat(ERR, ": ");
	_strcat(ERR, ver_str);
	_strcat(ERR, ": ");
	_strcat(ERR, my_info->args[0]);
	_strcat(ERR, ": Illegal number: ");
	_strcat(ERR, my_info->args[1]);
	_strcat(ERR, "\n\0");
	free(ver_str);

	return (ERR);
}
