#include "shell.h"

/**
 * CURR_FOLD - ZXCCCCCCCCCCCCCVXC
 * @path: ZXCCCCCCCCCCCCCVXC
 * @i: ZXCCCCCCCCCCCCCVXC
 * Return: 1 if theZXCCCCCCCCCCCCCVXC
 */
int CURR_FOLD(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

/**
 * SEARCH_COMM - ZXCCCCCCCCCCCCCVXC
 * @cmd: ZXCCCCCCCCCCCCCVXC
 * @_environ: ZXCCCCCCCCCCCCCVXC
 * Return: ZXCCCCCCCCCCCCCVXC
 */
char *SEARCH_COMM(char *cmd, char **_environ)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	path = ENV_VAR("PATH", _environ);
	if (path)
	{
		ptr_path = LETITDUMP(path);
		len_cmd = MEAUSE_IT(cmd);
		token_path = THROW_THEM(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (CURR_FOLD(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = MEAUSE_IT(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			OLDANOONE(dir, token_path);
			OLDONE(dir, "/");
			OLDONE(dir, cmd);
			OLDONE(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = THROW_THEM(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * DO_REQ - ZXCCCCCCCCCCCCCVXC
 * @my_info: ZXCCCCCCCCCCCCCVXC
 * Return: ZXCCCCCCCCCCCCCVXC
 */
int DO_REQ(shell_my_info_t *my_info)
{
	struct stat st;
	int i;
	char *input;

	input = my_info->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	CODE_ERR_GET(my_info, 127);
	return (-1);
}

/**
 * HAPPEND_ERR - ZXCCCCCCCCCCCCCVXC
 * @dir: ZXCCCCCCCCCCCCCVXC
 * @my_info: ZXCCCCCCCCCCCCCVXC
 * Return: 1 ZXCCCCCCCCCCCCCVXC
 */
int HAPPEND_ERR(char *dir, shell_my_info_t *my_info)
{
	if (dir == NULL)
	{
		CODE_ERR_GET(my_info, 127);
		return (1);
	}

	if (ARESAMEA(my_info->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			CODE_ERR_GET(my_info, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(my_info->args[0], X_OK) == -1)
		{
			CODE_ERR_GET(my_info, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * DO_COMMA - ZXCCCCCCCCCCCCCVXC
 * @my_info: ZXCCCCCCCCCCCCCVXC
 * Return: 1 ZXCCCCCCCCCCCCCVXC
 */
int DO_COMMA(shell_my_info_t *my_info)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = DO_REQ(my_info);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = SEARCH_COMM(my_info->args[0], my_info->_env);
		if (HAPPEND_ERR(dir, my_info) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = SEARCH_COMM(my_info->args[0], my_info->_env);
		else
			dir = my_info->args[0];
		execve(dir + exec, my_info->args, my_info->_env);
	}
	else if (pd < 0)
	{
		perror(my_info->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	my_info->CUURENT = state / 256;
	return (1);
}
