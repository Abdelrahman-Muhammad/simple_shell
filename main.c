#include "shell.h"

/**
 * L_ET_IT - ZZZZZZZZZZZZ
 * @my_info: ZZZZZZZZZZZZ
 */
void L_ET_IT(shell_my_info_t *my_info)
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
 * I_WANT_THESE - ZZZZZZZZZZZZ
 * @my_info: ZZZZZZZZZZZZ
 * @av: ZZZZZZZZZZZZ
 */
void I_WANT_THESE(shell_my_info_t *my_info, char **av)
{
	unsigned int i;

	my_info->av = av;
	my_info->input = NULL;
	my_info->args = NULL;
	my_info->CUURENT = 0;
	my_info->ADDAD = 1;

	for (i = 0; environ[i]; i++)
		;

	my_info->_env = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		my_info->_env[i] = LETITDUMP(environ[i]);
	}

	my_info->_env[i] = NULL;
	my_info->pid = INT_STR_CONV(getpid());
}

/**
 * main - INTRANCE
 * @ac: ZZZZZZZZZZZZ
 * @av: ZZZZZZZZZZZZ
 * Return: 0 ZZZZZZZZZZZZ ZZZZZZZZZZZZ.
 */
int main(int ac, char **av)
{
	shell_my_info_t my_info;
	(void) ac;

	signal(SIGINT, HANDLE_SIGNAL);
	I_WANT_THESE(&my_info, av);
	MAIN_APP(&my_info);
	L_ET_IT(&my_info);
	if (my_info.CUURENT < 0)
		return (255);
	return (my_info.CUURENT);
}
