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

char **REELOCKAGN(char **ptr, unsigned int old_size, unsigned int new_size);
void *REELOCK(void *ptr, unsigned int old_size, unsigned int new_size);
void DUPLIC_TE(void *newptr, const void *ptr, unsigned int size);

separator_list_t *FINISH_T(separator_list_t **head, char sep);
command_list_t *DO_SOME_TWKS(command_list_t **head, char *line);
void MAKE_IT_FLY(separator_list_t **head);
void LET_IT(command_list_t **head);

replacement_variable_t *ADD_IT_FLY(
	replacement_variable_t **head, int lvar, char *var, int lval);
void MAKE_IT_FLY_ZR(replacement_variable_t **head);

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

int ONE_CHAR(char *input, int *i);
int REP_CHK(char *input, int i);
int ERR_CHK(char *input, int i, char last);
int ERORR_CHK(shell_my_info_t *my_info, char *input);
void ERORR_GET(shell_my_info_t *my_info, char *input, int i, int bool);

char *TNMC_MER(char *in);
void MAIN_APP(shell_my_info_t *my_info);

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

ssize_t BUFFER_GET(char **lineptr, size_t *n, FILE *stream);
void USER_LINE_B(char **lineptr, size_t *n, char *buff,
								 size_t j);

char *GET_BUFFER_LN(int *i_line);

int DO_BUFF(shell_my_info_t *my_info);

char *SEARCH_COMM(char *cmd, char **_env);
int DO_COMMA(shell_my_info_t *my_info);
int CURR_FOLD(char *path, int *i);
int DO_REQ(shell_my_info_t *my_info);
int HAPPEND_ERR(char *dir, shell_my_info_t *my_info);

int ENV_VAR_GET(shell_my_info_t *my_info);
char *ENV_VAR(const char *name, char **_env);

int _SET_ENV(shell_my_info_t *my_info);
int _DNTSETENV(shell_my_info_t *my_infosh);
char *INF_CPY(char *name, char *value);
void ENV_SETTER(char *name, char *value, shell_my_info_t *my_info);
int ENV_VAR_COMPA(const char *nenv, const char *name);

void SOME_DEST(shell_my_info_t *my_info);
void PAR_DIR(shell_my_info_t *my_info);
void HOUSE_DIR(shell_my_info_t *my_info);
void PREV_DIC(shell_my_info_t *my_info);
int CURR_CHNG(shell_my_info_t *my_info);

int INT_LEN(int n);
int STR_INT_CONV(char *s);
char *INT_STR_CONV(int n);

char *ERR_CDD(shell_my_info_t *my_info);
char *N_T_FONDE(shell_my_info_t *my_info);
char *EXX_ERR(shell_my_info_t *my_info);
char *ERR_CD(shell_my_info_t *, char *, char *, char *);

char *ERR_MSG_ENV(shell_my_info_t *my_info);
char *ERR_126(shell_my_info_t *my_info);

void HELP_SHOER(void);
void BYE_HLP(void);
void SET_HLP(void);
void FOR_ALL_HLP(void);
void SET_HLP_SHOWER(void);

void HELP_SHOW(void);
void HELP_SHOWWW(void);
void HELP_SHOWW(void);

void HANDLE_SIGNAL(int sig);
int HELP_ME(shell_my_info_t *my_info);
int CODE_ERR_GET(shell_my_info_t *my_info, int eval);
int (*BULT_FUNC_GT(char *cmd))(shell_my_info_t *my_info);

int close_my_shell(shell_my_info_t *my_info);

#endif
