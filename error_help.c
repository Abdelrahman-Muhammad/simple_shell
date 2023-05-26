#include "shell.h"

/**
 * error_message_env - error message for env in get_env.
 * @my_info: my_info relevant (counter, arguments)
 * Return: error message.
 */
char *error_message_env(shell_my_info_t *my_info)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = int_to_string(my_info->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(my_info->av[0]) + _strlen(ver_str);
	length += _strlen(my_info->args[0]) + _strlen(msg) + 4;
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
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * error_message_path_126 - error msg for path and failure denied permission.
 * @my_info: my_info relevant (counter, arguments).
 * Return: The error string.
 */
char *error_message_path_126(shell_my_info_t *my_info)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = int_to_string(my_info->counter);
	length = _strlen(my_info->av[0]) + _strlen(ver_str);
	length += _strlen(my_info->args[0]) + 24;
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
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * print_help - Help information for the builtin help.
 */
void print_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * print_help_alias - Help information for the builtin alias.
 */
void print_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * print_help_cd - Help information for the builtin alias.
 */
void print_help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}
