#include "shell.h"

/**
 * HELP_SHOER - XBZXCXZCZXCZXC
 */
void HELP_SHOER(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, MEAUSE_IT(help));
	help = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, help, MEAUSE_IT(help));

}
/**
 * SET_HLP - XBZXCXZCZXCZXC
 */
void SET_HLP(void)
{

	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, MEAUSE_IT(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, MEAUSE_IT(help));
	help = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, help, MEAUSE_IT(help));
}
/**
 * SET_HLP_SHOWER - XBZXCXZCZXCZXC
 */
void SET_HLP_SHOWER(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, MEAUSE_IT(help));
	help = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, help, MEAUSE_IT(help));
}


/**
 * FOR_ALL_HLP - XBZXCXZCZXCZXC
 */
void FOR_ALL_HLP(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, MEAUSE_IT(help));
	help = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, help, MEAUSE_IT(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help, MEAUSE_IT(help));
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, MEAUSE_IT(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, MEAUSE_IT(help));
	help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, MEAUSE_IT(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, MEAUSE_IT(help));
}
/**
 * BYE_HLP - XBZXCXZCZXCZXC
 */
void BYE_HLP(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, MEAUSE_IT(help));
	help = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, help, MEAUSE_IT(help));
	help = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, help, MEAUSE_IT(help));
}
