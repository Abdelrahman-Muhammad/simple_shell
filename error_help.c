#include "shell.h"

/**
 * ERR_MSG_ENV - ZXVZXCVZXVZXCV
 * @my_info: ZXVZXCVZXCVZXCVXCV
 * Return: ERR ZXVCZXCVZXCV.
 */
char *ERR_MSG_ENV(shell_my_info_t *my_info)
{
	int length;
	char *ERR;
	char *ver_str;
	char *msg;

	ver_str = INT_STR_CONV(my_info->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(my_info->av[0]) + _strlen(ver_str);
	length += _strlen(my_info->args[0]) + _strlen(msg) + 4;
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
	_strcat(ERR, msg);
	_strcat(ERR, "\0");
	free(ver_str);

	return (ERR);
}
/**
 * ERR_126 - ADGDFJGHKB
 * @my_info: JKLJZZXCZXVZCXV
 * Return: ZXCZXCZXVXCV
 */
char *ERR_126(shell_my_info_t *my_info)
{
	int length;
	char *ver_str;
	char *ERR;

	ver_str = INT_STR_CONV(my_info->counter);
	length = _strlen(my_info->av[0]) + _strlen(ver_str);
	length += _strlen(my_info->args[0]) + 24;
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
	_strcat(ERR, ": Permission denied\n");
	_strcat(ERR, "\0");
	free(ver_str);
	return (ERR);
}

/**
 * HELP_SHOW - ASFSADGDFAGGGDAFG
 */
void HELP_SHOW(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * HELP_SHOWW - ADFGDFGDFGDFG
 */
void HELP_SHOWW(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * HELP_SHOWWW - As.SDGFDG
 */
void HELP_SHOWWW(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}
