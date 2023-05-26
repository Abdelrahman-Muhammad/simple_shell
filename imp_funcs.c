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
 * HELP_ME - HK';/.,MMMM.
 * @my_info: my_info ASTRUYKJ,MBNVVV
 * Return: SSYREYRTUYRRRRYT
*/
int HELP_ME(shell_my_info_t *my_info)
{

	if (my_info->args[1] == 0)
		FOR_ALL_HLP();
	else if (ARESAMEA(my_info->args[1], "setenv") == 0)
		SET_HLP();
	else if (ARESAMEA(my_info->args[1], "env") == 0)
		HELP_SHOER();
	else if (ARESAMEA(my_info->args[1], "unsetenv") == 0)
		SET_HLP_SHOWER();
	else if (ARESAMEA(my_info->args[1], "help") == 0)
		HELP_SHOW();
	else if (ARESAMEA(my_info->args[1], "exit") == 0)
		BYE_HLP();
	else if (ARESAMEA(my_info->args[1], "cd") == 0)
		HELP_SHOWWW();
	else if (ARESAMEA(my_info->args[1], "alias") == 0)
		HELP_SHOWW();
	else
		write(STDERR_FILENO, my_info->args[0],
		      MEAUSE_IT(my_info->args[0]));

	my_info->CUURENT = 0;
	return (1);
}

/**
 * CODE_ERR_GET - Invalid error code.
 * @my_info: Pointer to information about the error.
 * @eval: Pointer to the evaluation to be executed.
 * Return: 0 if successful, -1 otherwise.
 */
int CODE_ERR_GET(shell_my_info_t *my_info, int eval)
{
	char *nofix;

	switch (eval)
	{
	case -1:
		nofix = ERR_MSG_ENV(my_info);
		break;
	case 126:
		nofix = ERR_126(my_info);
		break;
	case 127:
		nofix = N_T_FONDE(my_info);
		break;
	case 2:
		if (ARESAMEA("exit", my_info->args[0]) == 0)
			nofix = EXX_ERR(my_info);
		else if (ARESAMEA("cd", my_info->args[0]) == 0)
			nofix = ERR_CDD(my_info);
		break;
	}

	if (nofix)
	{
		write(STDERR_FILENO, nofix, MEAUSE_IT(nofix));
		free(nofix);
	}

	my_info->CUURENT = eval;
	return (eval);
}

/**
 * BULT_FUNC_GT - gdjghjghj
 * @cmd: fghjfghjfghj
 * Return: fgjgfhjfgjh
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
		if (ARESAMEA(builtin[i].name, cmd) == 0)
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
		THATS_DIGIT = ARENUMBERS(my_info->args[1]);
		LEN_OF_STR = MEAUSE_IT(my_info->args[1]);
		ENO_NUM = ustatus > (unsigned int)INT_MAX;
		if (!THATS_DIGIT || LEN_OF_STR > 10 || ENO_NUM)
		{
			CODE_ERR_GET(my_info, 2);
			my_info->CUURENT = 2;
			return (1);
		}
		my_info->CUURENT = (ustatus % 256);
	}
	return (0);
}
