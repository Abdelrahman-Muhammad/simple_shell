#include "shell.h"

/**
 * FINISH_T - ZZZZZZZZZZZZZZZZZZZZZZ
 * @head: ZZZZZZZZZZZZZZZZZZZZZZ
 * @sep: ZZZZZZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZZ
 */
separator_list_t *FINISH_T(separator_list_t **head, char sep)
{
	separator_list_t *new_node, *temp_node = *head;

	new_node = malloc(sizeof(separator_list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->DIVIDE = sep;
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
 * MAKE_IT_FLY - ZZZZZZZZZZZZZZZZZZZZZZ
 * @head: ZZZZZZZZZZZZZZZZZZZZZZ
 */
void MAKE_IT_FLY(separator_list_t **head)
{
	separator_list_t *temp_node = NULL, *curr_node = *head;

	if (head == NULL || *head == NULL)
		return;

	for (; curr_node != NULL; curr_node = temp_node)
	{
		temp_node = curr_node->next;
		free(curr_node);
	}
	*head = NULL;
}

/**
 * DO_SOME_TWKS - ZZZZZZZZZZZZZZZZZZZZZZ
 * @head:ZZZZZZZZZZZZZZZZZZZZZZ
 * @line: ZZZZZZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZZ
 */
command_list_t *DO_SOME_TWKS(command_list_t **head, char *line)
{
	command_list_t *new_node, *temp_node = *head;

	new_node = malloc(sizeof(command_list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->line = line;
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
 * LET_IT - ZZZZZZZZZZZZZZZZZZZZZZ
 * @head: ZZZZZZZZZZZZZZZZZZZZZZ
 */
void LET_IT(command_list_t **head)
{
	command_list_t *temp_node = NULL, *curr_node = *head;

	if (head == NULL || *head == NULL)
		return;

	for (; curr_node != NULL; curr_node = temp_node)
	{
		temp_node = curr_node->next;
		free(curr_node);
	}
	*head = NULL;
}
