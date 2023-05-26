#include "shell.h"
/**
 * builtin_handler - check and execute if command is a builtin.
 * @args: command
 * Return: 1 for loop to continue or 0 not a builtin.
 */

int builtin_handler(char **args)
{
	int num = 6, i = 0;
	char *builtins[] = {"exit", "cd", "setenv", "unsetenv", "env", NULL};

	for (; i < num; i++)
	{
		if (my_strcmp(args[0], builtins[i]) == 0)
		{
			switch (i + 1)
			{
				case 1:
					_exitt(args);
					return (1);
				case 2:
					ch_dir(args);
					return (1);
				case 3:
					_setenv(args);
					return (1);
				case 4:
					_unsetenv(args);
					return (1);
				case 5:
					printenv(args);
					return (1);
				default:
					break;
			}
		}
	}
	return (0);
}

/**
 * ch_dir- changes the current working directory
 * @args: command/path
 * Return: 1
 */
int ch_dir(char **args)
{
	char *old_dir = _getenv("OLDPWD");
	char *pwd = _getenv("PWD");

	if (args[1] == NULL)
	{
		printf("HOME");
		return (1);
	}
	if (my_strcmp(args[1], "-") == 0)
	{
		if (chdir(old_dir) < 0)
			perror("chdir");
		update_dir(pwd);
		return (1);
	}
	if (chdir(args[1]) < 0)
		perror("chdir");
	update_dir(pwd);

	return (1);
}
/**
 * update_dir- updates the pwd and oldpwd
 * @pwd: pwd to update with.
 * Return: nothing.
 */
void update_dir(char *pwd)
{
	char *cwd = getcwd(NULL, 0);

	if (cwd == NULL)
	{
		perror("getcwd");
		return;
	}
	setenv("OLDPWD", pwd, 1);
	setenv("PWD", cwd, 1);
	free(cwd);
}
