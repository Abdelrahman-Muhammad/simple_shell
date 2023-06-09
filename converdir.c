#include "shell.h"

/**
 * PAR_DIR - ASTEUIIIIIPJKL
 * @my_info: ASFXHBCMBVJGHJ
 */
void PAR_DIR(shell_my_info_t *my_info)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_str_del_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = LETITDUMP(pwd);
	ENV_SETTER("OLDPWD", cp_pwd, my_info);
	dir = my_info->args[1];
	if (ARESAMEA(".", dir) == 0)
	{
		ENV_SETTER("PWD", cp_pwd, my_info);
		free(cp_pwd);
		return;
	}
	if (ARESAMEA("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_str_del_pwd = cp_pwd;
	RANDOM_IT(cp_str_del_pwd);
	cp_str_del_pwd = THROW_THEM(cp_str_del_pwd, "/");
	if (cp_str_del_pwd != NULL)
	{
		cp_str_del_pwd = THROW_THEM(NULL, "\0");

		if (cp_str_del_pwd != NULL)
			RANDOM_IT(cp_str_del_pwd);
	}
	if (cp_str_del_pwd != NULL)
	{
		chdir(cp_str_del_pwd);
		ENV_SETTER("PWD", cp_str_del_pwd, my_info);
	}
	else
	{
		chdir("/");
		ENV_SETTER("PWD", "/", my_info);
	}
	my_info->CUURENT = 0;
	free(cp_pwd);
}

/**
 * SOME_DEST - ASDGDJVMFBNB
 * @my_info: ASDGDFJHHFDJFH
 */
void SOME_DEST(shell_my_info_t *my_info)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	dir = my_info->args[1];
	if (chdir(dir) == -1)
	{
		CODE_ERR_GET(my_info, 2);
		return;
	}

	cp_pwd = LETITDUMP(pwd);
	ENV_SETTER("OLDPWD", cp_pwd, my_info);

	cp_dir = LETITDUMP(dir);
	ENV_SETTER("PWD", cp_dir, my_info);

	free(cp_pwd);
	free(cp_dir);

	my_info->CUURENT = 0;

	chdir(dir);
}

/**
 * PREV_DIC - AGFDSAF
 * @my_info: ASGFDHFGHFGH
 */
void PREV_DIC(shell_my_info_t *my_info)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = LETITDUMP(pwd);

	p_oldpwd = ENV_VAR("OLDPWD", my_info->_env);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = LETITDUMP(p_oldpwd);

	ENV_SETTER("OLDPWD", cp_pwd, my_info);

	if (chdir(cp_oldpwd) == -1)
		ENV_SETTER("PWD", cp_pwd, my_info);
	else
		ENV_SETTER("PWD", cp_oldpwd, my_info);

	p_pwd = ENV_VAR("PWD", my_info->_env);

	write(STDOUT_FILENO, p_pwd, MEAUSE_IT(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	my_info->CUURENT = 0;

	chdir(p_pwd);
}

/**
 * HOUSE_DIR - SADFHGDH
 * @my_info: ERYREYTRTY
 */
void HOUSE_DIR(shell_my_info_t *my_info)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = LETITDUMP(pwd);

	home = ENV_VAR("HOME", my_info->_env);

	if (home == NULL)
	{
		ENV_SETTER("OLDPWD", p_pwd, my_info);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		CODE_ERR_GET(my_info, 2);
		free(p_pwd);
		return;
	}

	ENV_SETTER("OLDPWD", p_pwd, my_info);
	ENV_SETTER("PWD", home, my_info);
	free(p_pwd);
	my_info->CUURENT = 0;
}

/**
 * CURR_CHNG - QWTERTSGDFG
 * @my_info: FJGHKGHJ
 * Return: 1 on ASGFHFD
 */
int CURR_CHNG(shell_my_info_t *my_info)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = my_info->args[1];

	if (dir != NULL)
	{
		ishome = ARESAMEA("$HOME", dir);
		ishome2 = ARESAMEA("~", dir);
		isddash = ARESAMEA("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		HOUSE_DIR(my_info);
		return (1);
	}

	if (ARESAMEA("-", dir) == 0)
	{
		PREV_DIC(my_info);
		return (1);
	}

	if (ARESAMEA(".", dir) == 0 || ARESAMEA("..", dir) == 0)
	{
		PAR_DIR(my_info);
		return (1);
	}

	SOME_DEST(my_info);

	return (1);
}
