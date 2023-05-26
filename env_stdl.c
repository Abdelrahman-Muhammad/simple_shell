#include "shell.h"

/**
 * ENV_VAR - DFGFDGDF
 * @name: ABDTDSFDGO
 * @_env: TEST
 * Return: DFGFGDFG
 */
char *ENV_VAR(const char *name, char **_env)
{
	char *ptr_env;
	int i, k;

	ptr_env = NULL;
	k = 0;
	for (i = 0; _env[i]; i++)
	{
		k = compare_environement_variable_name(_env[i], name);
		if (k)
		{
			ptr_env = _env[i];
			break;
		}
	}

	return (ptr_env + k);
}

/**
 * ENV_VAR_GET - FGHFGHFGH
 * @my_info: FGHFGHFGH
 * Return: 1 FGHFGHFGHERTYTRY
 */
int ENV_VAR_GET(shell_my_info_t *my_info)
{
	int i, j;

	for (i = 0; my_info->_env[i]; i++)
	{

		for (j = 0; my_info->_env[i][j]; j++)
			;

		write(STDOUT_FILENO, my_info->_env[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	my_info->status = 0;

	return (1);
}

/**
 * INT_LEN - this ASDSFAHGFH
 * @n: tDFGypFeFGFJBVM
 * Return: FGHDFHFHFH
 */
int INT_LEN(int n)
{
	unsigned int n1;
	int lenght = 1;

	if (n < 0)
	{
		lenght++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		lenght++;
		n1 = n1 / 10;
	}

	return (lenght);
}
/**
 * INT_STR_CONV - WTREUTRY
 * @n: ASHFHJHG
 * Return: StDGDFGring.
 */
char *INT_STR_CONV(int n)
{
	unsigned int n1;
	int lenght = INT_LEN(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (lenght + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + lenght) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}

	lenght--;
	do {
		*(buffer + lenght) = (n1 % 10) + '0';
		n1 = n1 / 10;
		lenght--;
	} while (n1 > 0);
	return (buffer);
}

/**
 * STR_INT_CONV - ASDGDFH
 * @s: FDGJGHKJ
 * Return: RYIIUPOIPO
 */
int STR_INT_CONV(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
