#include "shell.h"

/**
 * REVERP_IT - ZZZZZZZZZZZZZZ
 * @input: ZZZZZZZZZZZZ
 * @bool: ZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZ
 */
char *REVERP_IT(char *input, int bool)
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
 * NEW_IFO - ZZZZZZZZZZZZZZZZZZZZ
 * @head_s: ZZZZZZZZZZZZZZZZZZ
 * @head_l:ZZZZZZZZZZZZZZZZZZ
 * @input: ZZZZZZZZZZZZZZZZZZZZZ
 */
void NEW_IFO(
		separator_list_t **head_s, command_list_t **head_l, char *input)
{
	int i;
	char *line;

	input = REVERP_IT(input, 0);
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
	line = THROW_THEM(input, ";|&");
	while (line != NULL)
	{
		line = REVERP_IT(line, 1);
		DO_SOME_TWKS(head_l, line);
		line = THROW_THEM(NULL, ";|&");
	}
}

/**
 * COMIN_GET - ZZZZZZZZZZZZZZZ
 * @list_s: ZZZZZZZZZZZZZZZZZ
 * @list_l:ZZZZZZZZZZZZZZZ
 * @my_infosh: ZZZZZZZZZZZZZZZ
 */
void COMIN_GET(
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
 * DIVIDE_ITOP -ZZZZZZZZZZZZZZZZZZ
 * @my_info: ZZZZZZZZZZZZ
 * @input: ZZZZZZZZZZZ
 * Return: 0 ZZZZZZZZZZZZZZZZ
 */
int DIVIDE_ITOP(shell_my_info_t *my_info, char *input)
{
	int loop;
	separator_list_t *list_s, *head_s = NULL;
	command_list_t *list_l, *head_l = NULL;

	NEW_IFO(&head_s, &head_l, input);

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

		COMIN_GET(&list_s, &list_l, my_info);

		if (list_l != NULL)
			list_l = list_l->next;
	}
	MAKE_IT_FLY(&head_s);
	LET_IT(&head_l);

	return ((loop == 0) ? 0 : 1);
}

/**
 * split_input - ZZZZZZZZZZZZZZZZZZZ
 * @input: ZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZ
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

	token = THROW_THEM(input, TOKEN_DELIMITER);
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
		token = THROW_THEM(NULL, TOKEN_DELIMITER);
		tokens[i] = token;
	}
	return (tokens);
}
