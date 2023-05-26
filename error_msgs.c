#include "shell.h"

/**
 * ERR_CD - DFHFGHZXCXZC
 * @my_info: ZXCVZXCVZCXV
 * @msg: ZXVZXCVZXCV
 * @ERR: ZXVZXCVZXV
 * @ver_str: ZXCVXZCVXZCV
 * Return: ERR message
 */
char *ERR_CD(
		shell_my_info_t *my_info, char *msg, char *ERR, char *ver_str)
{
	char *illegal_flag;

	OLDANOONE(ERR, my_info->av[0]);
	OLDONE(ERR, ": ");
	OLDONE(ERR, ver_str);
	OLDONE(ERR, ": ");
	OLDONE(ERR, my_info->args[0]);
	OLDONE(ERR, msg);
	if (my_info->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = my_info->args[1][1];
		illegal_flag[2] = '\0';
		OLDONE(ERR, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		OLDONE(ERR, my_info->args[1]);
	}

	OLDONE(ERR, "\n");
	OLDONE(ERR, "\0");
	return (ERR);
}

/**
 * ERR_CDD - XZCVZXVZXCV
 * @my_info: ZXCVZXCVZXCV
 * Return: ZXVXZCVXCV
 */
char *ERR_CDD(shell_my_info_t *my_info)
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
		len_id = MEAUSE_IT(my_info->args[1]);
	}

	length = MEAUSE_IT(my_info->av[0]) + MEAUSE_IT(my_info->args[0]);
	length += MEAUSE_IT(ver_str) + MEAUSE_IT(msg) + len_id + 5;
	ERR = malloc(sizeof(char) * (length + 1));

	if (ERR == 0)
	{
		free(ver_str);
		return (NULL);
	}

	ERR = ERR_CD(my_info, msg, ERR, ver_str);

	free(ver_str);

	return (ERR);
}

/**
 * N_T_FONDE - gZXCVZXCVXCVZXCV
 * @my_info: ZXVZXCVXZCV
 * Return: ZZZZZZZZZZ
 */
char *N_T_FONDE(shell_my_info_t *my_info)
{
	int length;
	char *ERR;
	char *ver_str;

	ver_str = INT_STR_CONV(my_info->counter);
	length = MEAUSE_IT(my_info->av[0]) + MEAUSE_IT(ver_str);
	length += MEAUSE_IT(my_info->args[0]) + 16;
	ERR = malloc(sizeof(char) * (length + 1));
	if (ERR == 0)
	{
		free(ERR);
		free(ver_str);
		return (NULL);
	}
	OLDANOONE(ERR, my_info->av[0]);
	OLDONE(ERR, ": ");
	OLDONE(ERR, ver_str);
	OLDONE(ERR, ": ");
	OLDONE(ERR, my_info->args[0]);
	OLDONE(ERR, ": not found\n");
	OLDONE(ERR, "\0");
	free(ver_str);
	return (ERR);
}

/**
 * EXX_ERR - gXZVXCVXZCV
 * @my_info: ZXVZXCVXZCV
 * Return: ZXVCZXCV
 */
char *EXX_ERR(shell_my_info_t *my_info)
{
	int length;
	char *ERR;
	char *ver_str;

	ver_str = INT_STR_CONV(my_info->counter);
	length = MEAUSE_IT(my_info->av[0]) + MEAUSE_IT(ver_str);
	length += MEAUSE_IT(my_info->args[0]) + MEAUSE_IT(my_info->args[1]) + 23;
	ERR = malloc(sizeof(char) * (length + 1));
	if (ERR == 0)
	{
		free(ver_str);
		return (NULL);
	}
	OLDANOONE(ERR, my_info->av[0]);
	OLDONE(ERR, ": ");
	OLDONE(ERR, ver_str);
	OLDONE(ERR, ": ");
	OLDONE(ERR, my_info->args[0]);
	OLDONE(ERR, ": Illegal number: ");
	OLDONE(ERR, my_info->args[1]);
	OLDONE(ERR, "\n\0");
	free(ver_str);

	return (ERR);
}
