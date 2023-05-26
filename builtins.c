#include "shell.h"

/**
 * HANDLE_SIGNAL - HASFSDF C
 * @sig: SSSSFDSF
 */
void HANDLE_SIGNAL(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}

/**
 * HELP_ME - HK';/.,MMMM.,
 * @my_info: my_info ASTRUYKJ,MBNVVV
 * Return: SSYREYRTUYRRRRYT
*/
int HELP_ME(shell_my_info_t *my_info)
{

	if (my_info->args[1] == 0)
		print_help_general();
	else if (_strcmp(my_info->args[1], "setenv") == 0)
		print_help_setenv();
	else if (_strcmp(my_info->args[1], "env") == 0)
		print_help_env();
	else if (_strcmp(my_info->args[1], "unsetenv") == 0)
		print_help_unsetenv();
	else if (_strcmp(my_info->args[1], "help") == 0)
		print_help();
	else if (_strcmp(my_info->args[1], "exit") == 0)
		print_help_exit();
	else if (_strcmp(my_info->args[1], "cd") == 0)
		print_help_cd();
	else if (_strcmp(my_info->args[1], "alias") == 0)
		print_help_alias();
	else
		write(STDERR_FILENO, my_info->args[0],
		      _strlen(my_info->args[0]));

	my_info->status = 0;
	return (1);
}

/**
 * CODE_ERR_GET - ASHGFJHGKBVN
 * @my_info: AAAWRET SAGNV,.VCBXZV
 * @eval: AFSAF AGDHFGMVBC
 * Return: SAFHFGH
 */
int CODE_ERR_GET(shell_my_info_t *my_info, int eval)
{
	char *ERR;

	switch (eval)
	{
	case -1:
		ERR = error_message_env(my_info);
		break;
	case 126:
		ERR = error_message_path_126(my_info);
		break;
	case 127:
		ERR = error_message_not_found(my_info);
		break;
	case 2:
		if (_strcmp("exit", my_info->args[0]) == 0)
			ERR = error_message_exit_shell(my_info);
		else if (_strcmp("cd", my_info->args[0]) == 0)
			ERR = error_message_get_cd(my_info);
		break;
	}

	if (ERR)
	{
		write(STDERR_FILENO, ERR, _strlen(ERR));
		free(ERR);
	}

	my_info->status = eval;
	return (eval);
}

/**
 * BULT_FUNC_GT - builtin that pais the command in the arg
 * @cmd: command
 * Return: function pointer of the builtin command
 */
int (*BULT_FUNC_GT(char *cmd))(shell_my_info_t *)
{
	builtin_t builtin[] = {
		{ "env", ENV_VAR_GET },
		{ "exit", close_my_shell },
		{ "setenv", _SET_ENV },
		{ "unsetenv", _DNTSETENV },
		{ "cd", CURR_CHNG },
		{ "help", HELP_ME },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}

/**
 * close_my_shell - abdo function to cloose shell
 * @my_info: tha args
 * Return: 0 when success
 */
int close_my_shell(shell_my_info_t *my_info)
{
	unsigned int ustatus;
	int THATS_DIGIT;
	int LEN_OF_STR;
	int ENO_NUM;

	if (my_info->args[1] != NULL)
	{
		ustatus = STR_INT_CONV(my_info->args[1]);
		THATS_DIGIT = _isdigit(my_info->args[1]);
		LEN_OF_STR = _strlen(my_info->args[1]);
		ENO_NUM = ustatus > (unsigned int)INT_MAX;
		if (!THATS_DIGIT || LEN_OF_STR > 10 || ENO_NUM)
		{
			CODE_ERR_GET(my_info, 2);
			my_info->status = 2;
			return (1);
		}
		my_info->status = (ustatus % 256);
	}
	return (0);
}
