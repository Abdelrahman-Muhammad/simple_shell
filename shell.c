#include "shell.h"

#define MAX 100

/**
 * read_user_input - Reads user input from the command line
 * @user_input: Pointer to store the user input
 */
void read_user_input(char user_input[MAX])
{
    printf("#cisfun$ ");
    if (fgets(user_input, MAX, stdin) == NULL)
    {
        printf("\n");
        exit(0);
    }
    user_input[strcspn(user_input, "\n")] = '\0';
}

/**
 * execute_command - Executes the given command
 * @command: Command to execute
 * @program_name: Name of the program
 */
void execute_command(const char *command, const char *program_name)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        char *args[2];

        args[0] = (char *)command;
        args[1] = NULL;

        execvp(command, args);
        perror(program_name);
        exit(1);
    }
    else
    {
        int child_state;

        if (wait(&child_state) == -1)
        {
            perror("wait");
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
 * main - Entry point of the shell program
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
    char user_input[MAX];
    
    (void)argc;
    while (1)
    {
        read_user_input(user_input);
        execute_command(user_input, argv[0]);
    }

    return (0);
}
