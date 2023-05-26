#include "shell.h"

/**
 * REP_CHK - ZZZZZZZZZZZZ
 * @input: ZZZZZZZZZ
 * @i: ZZZZZZZZZZZ
 * Return: ZZZZZZZZZ
 */
int REP_CHK(char *input, int i)
{
	if (*(input - 1) == *input)
	{
		return (REP_CHK(input - 1, i + 1));
	}
	else
	{
		return (i);
	}
}

/**
 * ERR_CHK - ZZZZZZZZZZZZZ
 * @input: ZXCCCCCCCCCC
 * @i: ZXCCCCCCCCCCC
 * @last: ZXCVZXCVZXCV
 * Return: ZXCVZXCVZXCVXZV
 */
int ERR_CHK(char *input, int i, char last)
{
	int count = 0;

	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (ERR_CHK(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			count = REP_CHK(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}
	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			count = REP_CHK(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}
	return (ERR_CHK(input + 1, i + 1, *input));
}
/**
 * ONE_CHAR - ZZZZZZZZZZZZZZXCCCCCCCCCCCC
 * @input: XCCCCCCCCCCCC
 * @i: XCCCCCCCCCCCCC
 * Return: 1 XZCCCCCCCCCCCCXC
 */
int ONE_CHAR(char *input, int *i)
{
	*i = 0;

	while (input[*i])
	{
		if (input[*i] == ' ' || input[*i] == '\t')
		{
			++*i;
			continue;
		}
		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
		{
			return (-1);
		}
		break;
	}
	return (0);
}

/**
 * ERORR_GET - ZCXVVVVXZCVZXCV
 * @my_info: ZXVXZVCXZC
 * @input: ZXVXCZV
 * @i: ZXVXZCVXZCV
 * @bool: ZXVXZVCZXCV
 */
void ERORR_GET(shell_my_info_t *my_info, char *input, int i, int bool)
{
	char *msg, *msg2, *msg3, *ERR, *counter;
	int length;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}
	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax ERR: \"";
	msg3 = "\" unexpected\n";
	counter = INT_STR_CONV(my_info->counter);
	length = _strlen(my_info->av[0]) + _strlen(counter) + _strlen(msg) +
		_strlen(msg2) + _strlen(msg3) + 3;

	ERR = malloc(sizeof(char) * (length));
	if (ERR == NULL)
	{
		free(counter);
		return;
	}
	_strcpy(ERR, my_info->av[0]);
	_strcat(ERR, ": ");
	_strcat(ERR, counter);
	_strcat(ERR, msg2);
	_strcat(ERR, msg);
	_strcat(ERR, msg3);
	_strcat(ERR, "\0");
	ERR[length - 1] = '\0';

	write(STDERR_FILENO, ERR, length - 1);
	free(ERR);
	free(counter);
}

/**
 * ERORR_CHK - ZZCVZXVZXCVCZXV
 * @my_info: ZXVXZVZVX
 * @input: ZXCVZXVZV
 * Return: 1 ZVVVZXCVZXVZXV
 */
int ERORR_CHK(shell_my_info_t *my_info, char *input)
{
	int begin = 0, f_char = 0, error_pos = 0;

	f_char = ONE_CHAR(input, &begin);
	if (f_char == -1)
	{
		ERORR_GET(my_info, input, begin, 0);
		return (1);
	}
	error_pos = ERR_CHK(input + begin, 0, input[begin]);
	if (error_pos != 0)
	{
		ERORR_GET(my_info, input, begin + error_pos, 1);
		return (1);
	}
	return (0);
}
