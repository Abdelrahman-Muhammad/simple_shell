#include "shell.h"

/**
 * ERR_CD - DFHFGHZXCXZC
 * @my_info: ZXCVZXCVZCXV
 * @msg: ZXVZXCVZXCV
 * @nofix: ZXVZXCVZXV
 * @ver_str: ZXCVXZCVXZCV
 * Return: ZXCVXZCVXZCV
 */
char *ERR_CD(
		shell_my_info_t *my_info, char *msg, char *nofix, char *ver_str)
{
	char *illegal_flag;

	OLDANOONE(nofix, my_info->av[0]);
	OLDONE(nofix, ": ");
	OLDONE(nofix, ver_str);
	OLDONE(nofix, ": ");
	OLDONE(nofix, my_info->args[0]);
	OLDONE(nofix, msg);
	if (my_info->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = my_info->args[1][1];
		illegal_flag[2] = '\0';
		OLDONE(nofix, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		OLDONE(nofix, my_info->args[1]);
	}

	OLDONE(nofix, "\n");
	OLDONE(nofix, "\0");
	return (nofix);
}

/**
 * ERR_CDD - XZCVZXVZXCV
 * @my_info: ZXCVZXCVZXCV
 * Return: ZXVXZCVXCV
 */
char *ERR_CDD(shell_my_info_t *my_info)
{
	int length, len_id;
	char *nofix, *ver_str, *msg;

	ver_str = INT_STR_CONV(my_info->ADDAD);
	if (my_info->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = MEAUSE_IT(my_info->args[1]);
	}

	length = MEAUSE_IT(my_info->av[0]) + MEAUSE_IT(my_info->args[0]);
	length += MEAUSE_IT(ver_str) + MEAUSE_IT(msg) + len_id + 5;
	nofix = malloc(sizeof(char) * (length + 1));

	if (nofix == 0)
	{
		free(ver_str);
		return (NULL);
	}

	nofix = ERR_CD(my_info, msg, nofix, ver_str);

	free(ver_str);

	return (nofix);
}

/**
 * N_T_FONDE - gZXCVZXCVXCVZXCV
 * @my_info: ZXVZXCVXZCV
 * Return: ZZZZZZZZZZ
 */
char *N_T_FONDE(shell_my_info_t *my_info)
{
	int length;
	char *nofix;
	char *ver_str;

	ver_str = INT_STR_CONV(my_info->ADDAD);
	length = MEAUSE_IT(my_info->av[0]) + MEAUSE_IT(ver_str);
	length += MEAUSE_IT(my_info->args[0]) + 16;
	nofix = malloc(sizeof(char) * (length + 1));
	if (nofix == 0)
	{
		free(nofix);
		free(ver_str);
		return (NULL);
	}
	OLDANOONE(nofix, my_info->av[0]);
	OLDONE(nofix, ": ");
	OLDONE(nofix, ver_str);
	OLDONE(nofix, ": ");
	OLDONE(nofix, my_info->args[0]);
	OLDONE(nofix, ": not found\n");
	OLDONE(nofix, "\0");
	free(ver_str);
	return (nofix);
}

/**
 * EXX_ERR - gXZVXCVXZCV
 * @my_info: ZXVZXCVXZCV
 * Return: ZXVCZXCV
 */
char *EXX_ERR(shell_my_info_t *my_info)
{
	int length;
	char *nofix;
	char *ver_str;

	ver_str = INT_STR_CONV(my_info->ADDAD);
	length = MEAUSE_IT(my_info->av[0]) + MEAUSE_IT(ver_str);
	length += MEAUSE_IT(my_info->args[0]) + MEAUSE_IT(my_info->args[1]) + 23;
	nofix = malloc(sizeof(char) * (length + 1));
	if (nofix == 0)
	{
		free(ver_str);
		return (NULL);
	}
	OLDANOONE(nofix, my_info->av[0]);
	OLDONE(nofix, ": ");
	OLDONE(nofix, ver_str);
	OLDONE(nofix, ": ");
	OLDONE(nofix, my_info->args[0]);
	OLDONE(nofix, ": Illegal number: ");
	OLDONE(nofix, my_info->args[1]);
	OLDONE(nofix, "\n\0");
	free(ver_str);

	return (nofix);
}
