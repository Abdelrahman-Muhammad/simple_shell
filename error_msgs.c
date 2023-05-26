#include "shell.h"

/**
 * cd_error_message - this function concatenates the message for cd error
 * @my_info: my_info relevant (directory)
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */
char *cd_error_message(
		shell_my_info_t *my_info, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, my_info->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, my_info->args[0]);
	_strcat(error, msg);
	if (my_info->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = my_info->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, my_info->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_message_get_cd - this function error message for cd command in get_cd
 * @my_info: my_info relevant (directory)
 * Return: Error message
 */
char *error_message_get_cd(shell_my_info_t *my_info)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = int_to_string(my_info->counter);
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
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = cd_error_message(my_info, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * error_message_not_found - generic error message for command not found
 * @my_info: my_info relevant (counter, arguments)
 * Return: Error message
 */
char *error_message_not_found(shell_my_info_t *my_info)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = int_to_string(my_info->counter);
	length = _strlen(my_info->av[0]) + _strlen(ver_str);
	length += _strlen(my_info->args[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, my_info->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, my_info->args[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * error_message_exit_shell - generic error message for exit in get_exit
 * @my_info: my_info relevant (counter, arguments)
 * Return: Error message
 */
char *error_message_exit_shell(shell_my_info_t *my_info)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = int_to_string(my_info->counter);
	length = _strlen(my_info->av[0]) + _strlen(ver_str);
	length += _strlen(my_info->args[0]) + _strlen(my_info->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, my_info->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, my_info->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, my_info->args[1]);
	_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}
