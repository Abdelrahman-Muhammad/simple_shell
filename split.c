#include "shell.h"

/**
 * swap_char - this function swaps | and & for non-printed chars
 * @input: input string
 * @bool: type of swap
 * Return: returns swapped string
 */
char *swap_char(char *input, int bool)
{
	int i;

	if (bool == 0)
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				if (input[i + 1] != '|')
					input[i] = 16;
				else
					i++;
			}

			if (input[i] == '&')
			{
				if (input[i + 1] != '&')
					input[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			input[i] = (input[i] == 16 ? '|' : input[i]);
			input[i] = (input[i] == 12 ? '&' : input[i]);
		}
	}
	return (input);
}

/**
 * add_nodes - this function adds separators and cmd lines in the lists
 * @head_s: pointer to head node of separatorlist
 * @head_l: pointer to head node of command lines list
 * @input: input string
 */
void add_nodes(
		separator_list_t **head_s, command_list_t **head_l, char *input)
{
	int i;
	char *line;

	input = swap_char(input, 0);
	for (i = 0; input[i]; i++)
	{
		if (input[i] == ';')
			FINISH_T(head_s, input[i]);

		if (input[i] == '|' || input[i] == '&')
		{
			FINISH_T(head_s, input[i]);
			i++;
		}
	}
	line = _str_del(input, ";|&");
	while (line != NULL)
	{
		line = swap_char(line, 1);
		DO_SOME_TWKS(head_l, line);
		line = _str_del(NULL, ";|&");
	}
}

/**
 * get_next - this function moves to the next stored command line
 * @list_s: separatorlist
 * @list_l: command line list
 * @my_infosh: my_info structure pointer
 */
void get_next(
		separator_list_t **list_s, command_list_t **list_l, shell_my_info_t *my_infosh)
{
	int loop_sep = 1;
	separator_list_t *ls_s = *list_s;
	command_list_t *ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (my_infosh->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}
	*list_s = ls_s;
	*list_l = ls_l;
}
/**
 * split_cmd_op - splits command lines according to
 *				the separators ;, | and &, and executes them
 * @my_info: my_info structure
 * @input: input string
 * Return: 0 to exit, 1 to continue
 */
int split_cmd_op(shell_my_info_t *my_info, char *input)
{
	int loop;
	separator_list_t *list_s, *head_s = NULL;
	command_list_t *list_l, *head_l = NULL;

	add_nodes(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		my_info->input = list_l->line;
		my_info->args = split_input(my_info->input);
		loop = DO_BUFF(my_info);
		free(my_info->args);

		if (loop == 0)
			break;

		get_next(&list_s, &list_l, my_info);

		if (list_l != NULL)
			list_l = list_l->next;
	}
	MAKE_IT_FLY(&head_s);
	LET_IT(&head_l);

	return ((loop == 0) ? 0 : 1);
}

/**
 * split_input - this function tokenizes the input string
 * @input: input string.
 * Return: returns the splitted string
 */
char **split_input(char *input)
{
	char *token, **tokens;
	size_t i, bufsize = TOKEN_BUFFER_SIZE;

	tokens = malloc(sizeof(char *) * (bufsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation ERR\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _str_del(input, TOKEN_DELIMITER);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bufsize)
		{
			bufsize += TOKEN_BUFFER_SIZE;
			tokens = REELOCKAGN(tokens, i, sizeof(char *) * bufsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation ERR\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _str_del(NULL, TOKEN_DELIMITER);
		tokens[i] = token;
	}
	return (tokens);
}
