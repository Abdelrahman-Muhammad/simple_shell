#include "shell.h"
/**
 * execute- executes th commands entered by user
 * @args: commands to ecxecute
 * @ac: number of arguments
 * Return: 1 to main to continue loop
 */

int execute(int ac, char **args)
{
	char *message = NULL;

	builtin_handler(args);
	if ((_strstr(args[0], "/")) == NULL)
	{
		args[0] = path_handler(args);
		if (args[0] == NULL)
		{
			write(STDERR_FILENO, "./hsh: 1: ", 10);
			write(STDERR_FILENO, args[0], my_strlen(args[0]));
			message = " : not found\n";
			write(STDERR_FILENO, message, my_strlen(message));
			return (1);
		}
	}
	(void)ac;
	return (process(args));
}

/**
 * process- creates a process.
 * @args: arguments
 * Return: 1
 */
int process(char **args)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error: fork");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) < 0)
			perror("./hsh");
		exit(EXIT_SUCCESS);
	}
	wait(&status);

	return (1);
}
