#include "shell.h"

/**
 * ENV_VAR_COMPA - SAGFDSGDFGDFG
 * @nenv: XBNCVMNBVM
 * @name: SAGDFAGSDFASD
 * Return: 0 SAGDAGWERRREWTERT
 */
int ENV_VAR_COMPA(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * INF_CPY - JKHL;HJKL
 * @name: nameASDGDFGHDHGF
 * @value: value ASFSCXNBCBV
 * Return: SFSAGDFSGDF.
 */
char *INF_CPY(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * ENV_SETTER - SAHCN,GHKHL
 * @name: ASHYRTUIIYU
 * @value: ASFBHCMMVBNe
 * @my_info: ASYYYTIYUIYUTREY
 * Return: no return
 */
void ENV_SETTER(char *name, char *value, shell_my_info_t *my_info)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; my_info->_env[i]; i++)
	{
		var_env = _strdup(my_info->_env[i]);
		name_env = _str_del(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(my_info->_env[i]);
			my_info->_env[i] = INF_CPY(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	my_info->_env = REELOCKAGN(my_info->_env, i, sizeof(char *) * (i + 2));
	my_info->_env[i] = INF_CPY(name, value);
	my_info->_env[i + 1] = NULL;
}

/**
 * _SET_ENV - ASHFGKMBVMB
 * @my_info: my_info ASDHFGJHGKKBN
 * Return: 1 DASFERYIUYIYUIY
 */
int _SET_ENV(shell_my_info_t *my_info)
{

	if (my_info->args[1] == NULL || my_info->args[2] == NULL)
	{
		CODE_ERR_GET(my_info, -1);
		return (1);
	}

	ENV_SETTER(my_info->args[1], my_info->args[2], my_info);

	return (1);
}

/**
 * _DNTSETENV - ASHDFHHFK
 * @my_info: SADFGDFGHKJG
 * Return: 1 SFAWETHJL
 */
int _DNTSETENV(shell_my_info_t *my_info)
{
	char **realloc_env;
	char *var_env, *name_env;
	int i, j, k;

	if (my_info->args[1] == NULL)
	{
		CODE_ERR_GET(my_info, -1);
		return (1);
	}
	k = -1;
	for (i = 0; my_info->_env[i]; i++)
	{
		var_env = _strdup(my_info->_env[i]);
		name_env = _str_del(var_env, "=");
		if (_strcmp(name_env, my_info->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		CODE_ERR_GET(my_info, -1);
		return (1);
	}
	realloc_env = malloc(sizeof(char *) * (i));
	for (i = j = 0; my_info->_env[i]; i++)
	{
		if (i != k)
		{
			realloc_env[j] = my_info->_env[i];
			j++;
		}
	}
	realloc_env[j] = NULL;
	free(my_info->_env[k]);
	free(my_info->_env);
	my_info->_env = realloc_env;
	return (1);
}
