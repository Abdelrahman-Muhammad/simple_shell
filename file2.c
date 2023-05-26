#include "shell.h"

/**
 * ADD_IT_FLY - ZZZZZZZZZZZZZZZZZZZZZ
 * @head: ZZZZZZZZZZZZZZZZZZZZZ
 * @lvar: ZZZZZZZZZZZZZZZZZZZZZ
 * @val: ZZZZZZZZZZZZZZZZZZZZZ
 * @lval: ZZZZZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZ
 */
replacement_variable_t *ADD_IT_FLY(
		replacement_variable_t **head, int lvar, char *val, int lval)
{
	replacement_variable_t *new_node, *temp_node = *head;

	new_node = malloc(sizeof(replacement_variable_t));
	if (new_node == NULL)
		return (NULL);

	new_node->len_var = lvar;
	new_node->len_val = lval;
	new_node->val = val;
	new_node->next = NULL;

	if (temp_node == NULL)
		*head = new_node;
	else
	{
		while (temp_node->next != NULL)
		{
			temp_node = temp_node->next;
		}
		temp_node->next = new_node;
	}
	return (*head);
}

/**
 * MAKE_IT_FLY_ZR - ZZZZZZZZZZZZZZZZZZZZZ
 * @head: ZZZZZZZZZZZZZZZZZZZZZ
 */
void MAKE_IT_FLY_ZR(replacement_variable_t **head)
{
	replacement_variable_t *temp_node = NULL, *curr_node = *head;

	if (head == NULL || *head == NULL)
		return;

	for (; curr_node != NULL; curr_node = temp_node)
	{
		temp_node = curr_node->next;
		free(curr_node);
	}
	*head = NULL;
}

