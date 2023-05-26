#include "shell.h"

/**
 * compare_environement_variable_name - this function compares
 *					environment variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 * Return: 0 if are not equal. Another value if they are.
 */
int compare_environement_variable_name(const char *nenv, const char *name)
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
 * copy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
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
 * set_env - sets an environment variable
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @my_info: my_info structure (environ)
 * Return: no return
 */
void set_env(char *name, char *value, shell_my_info_t *my_info)
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
			my_info->_env[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	my_info->_env = _reallocdp(my_info->_env, i, sizeof(char *) * (i + 2));
	my_info->_env[i] = copy_info(name, value);
	my_info->_env[i + 1] = NULL;
}

/**
 * _setenv - compares env variables names
 * with the name passed.
 * @my_info: my_info relevant (env name and env value)
 * Return: 1 on success.
 */
int _setenv(shell_my_info_t *my_info)
{

	if (my_info->args[1] == NULL || my_info->args[2] == NULL)
	{
		err_code_generate(my_info, -1);
		return (1);
	}

	set_env(my_info->args[1], my_info->args[2], my_info);

	return (1);
}

/**
 * _unsetenv - deletes a environment variable
 * @my_info: my_info relevant (env name)
 * Return: 1 on success.
 */
int _unsetenv(shell_my_info_t *my_info)
{
	char **realloc_env;
	char *var_env, *name_env;
	int i, j, k;

	if (my_info->args[1] == NULL)
	{
		err_code_generate(my_info, -1);
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
		err_code_generate(my_info, -1);
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
