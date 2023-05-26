#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define TOKEN_BUFFER_SIZE 128
#define TOKEN_DELIMITER " \t\r\n\a"

/**
 * struct shell_my_info - this struct contains all relevant my_info on runtime
 * @status: last status of the shell
 * @counter: lines counter
 * @pid: process ID of the shell
 * @av: ARGument Vector
 * @input: command line written by the user
 * @args: arguments of the command line
 * @_env: environment variable
 */
typedef struct shell_my_info
{
	int status;
	int counter;
	char *pid;
	char **av;
	char *input;
	char **args;
	char **_env;
} shell_my_info_t;

/**
 * struct separator_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 */
typedef struct separator_list_s
{
	char separator;
	struct separator_list_s *next;
} separator_list_t;

/**
 * struct command_list_s - single linked list
 * @line: command line
 * @next: next node
 */
typedef struct command_list_s
{
	char *line;
	struct command_list_s *next;
} command_list_t;

/**
 * struct replace_var - single linked list
 * @val: variable value
 * @len_var: variable length
 * @len_val: value length
 * @next: next node
 */
typedef struct replacement_variable_list
{
	char *val;
	int len_var;
	int len_val;
	struct replacement_variable_list *next;
} replacement_variable_t;

/**
 * struct builtin_s - struct for builtin command arguments.
 * @name: The name of the builtin command i.e ls, cd, echo
 * @f: my_info type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(shell_my_info_t *my_info);
} builtin_t;

/* Pointer to an array of pointers to strings called the environment */
extern char **environ;

char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _memcpy(void *newptr, const void *ptr, unsigned int size);

separator_list_t *add_separator_node_end(separator_list_t **head, char sep);
command_list_t *add_command_node_end(command_list_t **head, char *line);
void free_separator_list(separator_list_t **head);
void free_command_list(command_list_t **head);

replacement_variable_t *add_replacement_variable_node(
	replacement_variable_t **head, int lvar, char *var, int lval);
void free_replacement_variable_list(replacement_variable_t **head);

int _strcmp(char *s1, char *s2);
int _strspn(char *s, char *s2);
char *_strchr(char *s, char c);
char *_strcpy(char *des, char *src);
char *_strcat(char *des, const char *src);

int _strlen(const char *s);
int _isdigit(const char *s);
int cmp_chars(char str[], const char *delim);
char *_str_del(char str[], const char *delim);
char *_strdup(const char *s);

void str_rev(char *s);

int check_first_char(char *input, int *i);
int check_rep(char *input, int i);
int check_err(char *input, int i, char last);
int check_syntax_err(shell_my_info_t *my_info, char *input);
void print_syntax_err(shell_my_info_t *my_info, char *input, int i, int bool);

char *rem_cmnt(char *in);
void run_shell_loop(shell_my_info_t *my_info);

/* split.c */
char **split_input(char *input);
char *swap_char(char *input, int bool);
int split_cmd_op(shell_my_info_t *my_info, char *input);
void des(separator_list_t **head_s, command_list_t **head_l,
		 char *input);
void get_next(
	separator_list_t **list_s, command_list_t **list_l, shell_my_info_t *my_infosh);

/**replacing varibables*/
char *replace_variable(char *input, shell_my_info_t *my_info);
char *get_replaced_input(replacement_variable_t **head, char *input,
						 char *new_input, int nlen);
int replace_variables(replacement_variable_t **h, char *in, char *st,
					  shell_my_info_t *my_info);
void check_for_environment_variables(replacement_variable_t **h, char *in,
									 shell_my_info_t *my_info);

ssize_t get_input_line(char **lineptr, size_t *n, FILE *stream);
void read_input_line_from_buffer(char **lineptr, size_t *n, char *buff,
								 size_t j);

char *read_input_line(int *i_line);

int execute_input_line(shell_my_info_t *my_info);

char *find_cmd(char *cmd, char **_env);
int exec_cmmd(shell_my_info_t *my_info);
int _current_dir(char *path, int *i);
int cmd_exec(shell_my_info_t *my_info);
int check_cmd_err(char *dir, shell_my_info_t *my_info);

int ENV_VAR_GET(shell_my_info_t *my_info);
char *ENV_VAR(const char *name, char **_env);

int _setenv(shell_my_info_t *my_info);
int _unsetenv(shell_my_info_t *my_infosh);
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, shell_my_info_t *my_info);
int compare_environement_variable_name(const char *nenv, const char *name);

void change_to_dir(shell_my_info_t *my_info);
void change_to_dot_dir(shell_my_info_t *my_info);
void change_to_home_dir(shell_my_info_t *my_info);
void change_to_ols_dir(shell_my_info_t *my_info);
int change_directory_shell(shell_my_info_t *my_info);

int INT_LEN(int n);
int STR_INT_CONV(char *s);
char *INT_STR_CONV(int n);

char *error_message_get_cd(shell_my_info_t *my_info);
char *error_message_not_found(shell_my_info_t *my_info);
char *error_message_exit_shell(shell_my_info_t *my_info);
char *cd_error_message(shell_my_info_t *, char *, char *, char *);

char *error_message_env(shell_my_info_t *my_info);
char *error_message_path_126(shell_my_info_t *my_info);

void print_help_env(void);
void print_help_exit(void);
void print_help_setenv(void);
void print_help_general(void);
void print_help_unsetenv(void);

void print_help(void);
void print_help_cd(void);
void print_help_alias(void);

void sign_int_handle(int sig);
int req_help(shell_my_info_t *my_info);
int err_code_generate(shell_my_info_t *my_info, int eval);
int (*get_builtin_function(char *cmd))(shell_my_info_t *my_info);

int close_my_shell(shell_my_info_t *my_info);

#endif
