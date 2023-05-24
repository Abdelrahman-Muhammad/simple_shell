#include "shell.h"


#define MAX 100
/**
 * read_user_input - check the code
 * @user_input: user_input
 * void: Always 0.
 */
void read_user_input(char user_input[MAX])
{
	printf("#cisfun$");
	if (fgets(user_input, MAX, stdin) == NULL)
	{
		printf("\n");
		exit(0);
	}
	user_input[strcspn(user_input, "\n")] = '\0';
}
/**
 * execute_command - check the code
 * @user_input: user_input
 * Return: Always void.
 */
void execute_command(char user_input[MAX])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		printf("Error: %s\n", strerror(errno));
		exit(1);
	}
	else if (pid == 0)
	{
		char *args[2];
		
		args[0] = user_input;
		args[1] = NULL;
		
		execvp(user_input, args);
		perror("Error");
		exit(1);
	}
	else
	{
		int child_state;

		if (wait(&child_state) == -1)
		{
			perror("Child Process Err");
			exit(1);
		}
		if (WIFEXITED(child_state) && WEXITSTATUS(child_state) == 0)
		{
			return;
		}
		else
		{
			return;
		}
	}
}
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)

{
	char user_input[MAX];

	while (1)
	{
		read_user_input(user_input);
		execute_command(user_input);
	}
	return (0);
}

