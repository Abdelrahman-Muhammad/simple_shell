#include "shell.h"

#define MAX 100

/**
 * read_user_input - Reads user input from the command line
 * @user_input: Pointer to store the user input
 */
void read_user_input(char *user_input)
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
void execute_command(char *command, const char *program_name)
{
    pid_t pid;

    char **args = malloc(2 * sizeof(char *));
    if (args == NULL)
    {
        perror("malloc");
        exit(1);
    }

    args[0] = command;
    args[1] = NULL;

    if ((pid = fork()) == -1)
    {
        perror("fork");
        free(args);
        exit(1);
    }
    else if (pid == 0)
    {
        execvp(command, args);
        perror(program_name);
        free(args);
        exit(1);
    }
    else
    {
        int child_state;
        if (wait(&child_state) == -1)
        {
            perror("wait");
            free(args);
            exit(1);
        }
        if (WIFEXITED(child_state) && WEXITSTATUS(child_state) == 0)
        {
            free(args);
            return;
        }
        else
        {
            free(args);
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
    char *user_input = NULL;
    size_t input_size = 0;

    if (argc == 1)
    {
        while (1)
        {
            printf("#cisfun$ ");
            if (getline(&user_input, &input_size, stdin) == -1)
            {
                printf("\n");
                free(user_input);
                exit(0);
            }
            user_input[strcspn(user_input, "\n")] = '\0';

            execute_command(user_input, argv[0]);
        }
    }
    else if (argc == 2)
    {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL)
        {
            perror("fopen");
            exit(1);
        }

        while (getline(&user_input, &input_size, file) != -1)
        {
            user_input[strcspn(user_input, "\n")] = '\0';
            execute_command(user_input, argv[0]);
        }

        fclose(file);
        free(user_input);
    }
    else
    {
        fprintf(stderr, "Usage: %s [script_file]\n", argv[0]);
        exit(1);
    }

    return 0;
}
