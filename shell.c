#include "shell.h"
#include <stdlib.h>
#include <string.h>

#define MAX 100

/**
 * read_user_input - Reads user input from the command line
 * @user_input: Pointer to store the user input
 */
void read_user_input(char *user_input)
{
    if (fgets(user_input, MAX, stdin) == NULL)
    {
        printf("\n");
        exit(EXIT_SUCCESS);
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

    char **args = malloc(3 * sizeof(char *));
    if (args == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    char *token;
    int i = 0;
    token = strtok(command, " ");
    while (token != NULL)
    {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL;

    if ((pid = fork()) == -1)
    {
        perror("fork");
        free(args);
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execve(args[0], args, NULL);
        perror(program_name);
        free(args);
        exit(EXIT_FAILURE);
    }
    else
    {
        int child_state;
        if (wait(&child_state) == -1)
        {
            perror("wait");
            free(args);
            exit(EXIT_FAILURE);
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
    int interactive_mode = 0;

    if (argc == 1)
    {
        interactive_mode = 1;
    }
    else if (argc == 2)
    {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL)
        {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        while (getline(&user_input, &input_size, file) != -1)
        {
            user_input[strcspn(user_input, "\n")] = '\0';
            execute_command(user_input, argv[0]);
        }

        fclose(file);
        free(user_input);
        return 0;
    }
    else
    {
        fprintf(stderr, "Usage: %s [script_file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        if (interactive_mode)
            printf("#cisfun$ ");

        if (getline(&user_input, &input_size, stdin) == -1)
        {
            printf("\n");
            free(user_input);
            exit(EXIT_SUCCESS);
        }
        user_input[strcspn(user_input, "\n")] = '\0';

        execute_command(user_input, argv[0]);
    }

    return 0;
}
