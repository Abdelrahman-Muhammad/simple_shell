#include "shell.h"

/**
 * free_my_info - frees my_info structure
 * @my_info: my_info structure
 */
void free_my_info(shell_my_info_t *my_info)
{
	unsigned int i;

	for (i = 0; my_info->_env[i]; i++)
	{
		free(my_info->_env[i]);
	}

	free(my_info->_env);
	free(my_info->pid);
}

/**
 * set_my_info - Initialize my_info structure
 * @my_info: my_info structure
 * @av: argument vector
 */
void set_my_info(shell_my_info_t *my_info, char **av)
{
	unsigned int i;

	my_info->av = av;
	my_info->input = NULL;
	my_info->args = NULL;
	my_info->status = 0;
	my_info->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	my_info->_env = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		my_info->_env[i] = _strdup(environ[i]);
	}

	my_info->_env[i] = NULL;
	my_info->pid = int_to_string(getpid());
}

/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	shell_my_info_t my_info;
	(void) ac;

	signal(SIGINT, sign_int_handle);
	set_my_info(&my_info, av);
	run_shell_loop(&my_info);
	free_my_info(&my_info);
	if (my_info.status < 0)
		return (255);
	return (my_info.status);
}
