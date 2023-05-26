#include "shell.h"

/**
 * sign_int_handle - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void sign_int_handle(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}

/**
 * req_help - function that retrieves help messages according builtin
 * @my_info: my_info structure (args and input)
 * Return: Return 0
*/
int req_help(shell_my_info_t *my_info)
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
 * err_code_generate - calls the error according the builtin, syntax or permission
 * @my_info: my_info structure that contains arguments
 * @eval: error value
 * Return: error
 */
int err_code_generate(shell_my_info_t *my_info, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_message_env(my_info);
		break;
	case 126:
		error = error_message_path_126(my_info);
		break;
	case 127:
		error = error_message_not_found(my_info);
		break;
	case 2:
		if (_strcmp("exit", my_info->args[0]) == 0)
			error = error_message_exit_shell(my_info);
		else if (_strcmp("cd", my_info->args[0]) == 0)
			error = error_message_get_cd(my_info);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	my_info->status = eval;
	return (eval);
}

/**
 * get_builtin_function - builtin that pais the command in the arg
 * @cmd: command
 * Return: function pointer of the builtin command
 */
int (*get_builtin_function(char *cmd))(shell_my_info_t *)
{
	builtin_t builtin[] = {
		{ "env", ENV_VAR_GET },
		{ "exit", close_my_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", change_directory_shell },
		{ "help", req_help },
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
	int is_digit;
	int str_len;
	int big_number;

	if (my_info->args[1] != NULL)
	{
		ustatus = STR_INT_CONV(my_info->args[1]);
		is_digit = _isdigit(my_info->args[1]);
		str_len = _strlen(my_info->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			err_code_generate(my_info, 2);
			my_info->status = 2;
			return (1);
		}
		my_info->status = (ustatus % 256);
	}
	return (0);
}
