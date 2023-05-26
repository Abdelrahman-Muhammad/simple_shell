#include "shell.h"

/**
 * ENV_VAR_CHKIT -ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * @h: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * @in: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * @my_info: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 */
void ENV_VAR_CHKIT(
		replacement_variable_t **h, char *in, shell_my_info_t *my_info)
{
	int row, chr, j, lval;
	char **_envr = my_info->_env;

	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = MEAUSE_IT(_envr[row] + chr + 1);
				ADD_IT_FLY(
						h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}
	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}
	ADD_IT_FLY(h, j, NULL, 0);
}
/**
 * CHNG_VAR - ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * @h: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * @in: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * @st: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * @my_info: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 */
int CHNG_VAR(
		replacement_variable_t **h, char *in, char *st, shell_my_info_t *my_info)
{
	int i, lst = MEAUSE_IT(st), lpd = MEAUSE_IT(my_info->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				ADD_IT_FLY(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				ADD_IT_FLY(h, 2, my_info->pid, lpd), i++;
			else if (in[i + 1] == '\n')
				ADD_IT_FLY(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				ADD_IT_FLY(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				ADD_IT_FLY(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				ADD_IT_FLY(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				ADD_IT_FLY(h, 0, NULL, 0);
			else
				ENV_VAR_CHKIT(h, in + i, my_info);
		}
	}
	return (i);
}

/**
 * ARE_COMING - ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * @head: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * @input: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * @new_input: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * @nlen: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 */
char *ARE_COMING(
		replacement_variable_t **head, char *input, char *new_input, int nlen)
{
	int i, j, k;
	replacement_variable_t *index = *head;

	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(index->len_var) && !(index->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (index->len_var && !(index->len_val))
			{
				for (k = 0; k < index->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < index->len_val; k++)
				{
					new_input[i] = index->val[k];
					i++;
				}
				j += (index->len_var);
				i--;
			}
			index = index->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}
	return (new_input);
}

/**
 * *CHNAG_THEM - ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * @input: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * @my_infosh: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZZZZZ
 */
char *CHNAG_THEM(char *input, shell_my_info_t *my_infosh)
{
	replacement_variable_t *head, *index;
	char *CUURENT, *new_input;
	int olen, nlen;

	CUURENT = INT_STR_CONV(my_infosh->CUURENT);
	head = NULL;

	olen = CHNG_VAR(&head, input, CUURENT, my_infosh);

	if (head == NULL)
	{
		free(CUURENT);
		return (input);
	}

	index = head;
	nlen = 0;

	while (index != NULL)
	{
		nlen += (index->len_val - index->len_var);
		index = index->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = ARE_COMING(&head, input, new_input, nlen);

	free(input);
	free(CUURENT);
	MAKE_IT_FLY_ZR(&head);

	return (new_input);
}
