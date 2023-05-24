#include "shell.h"
/**
 * main - check the code
 *
 * Return: Always 0.
 */

#define MAX 100

int main(void)
{
	char user_input[MAX];

	while (1)
	{
		printf("~alxshell$ ");

		if (fgets(user_input, MAX, stdin) == NULL)
		{
			printf("\n");
            
			exit(0);
		}
		user_input[strcspn(user_input, "\n")] = '\0';

		pid_t pid = fork();

		if (pid == -1)

		{
			perror("fork");

            printf("Error: %s\n", strerror(errno));

			exit(1);
		}
		else if (pid == 0)
		{
			char *args[] = {user_input,NULL};

			execve(user_input, args,__environ);

			perror("Error");

			exit(1);
		}
		else
		{
			int child_state;
			if (wait(&child_state) == -1)
			{
				perror("Chile Process Err");
				exit(1);
			}

			if (WIFEXITED(child_state) && WEXITSTATUS(child_state) == 0)
			{
				continue;
			}
			else
			{
				printf("%s: cmnd Not Found\n", user_input);

				continue;
			}
		}

	}

	return (0);
}
