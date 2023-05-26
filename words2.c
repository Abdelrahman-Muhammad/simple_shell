#include "shell.h"

/**
 * LETITDUMP - ZZZZZZZZZZZZZZZZ
 * @s: ZZZZZZZZZZZZZZZZZZZZZZZZZZZZreturns the duplicated string
 */
char *LETITDUMP(const char *s)
{
	size_t len = MEAUSE_IT(s) + 1;
	char *copy = malloc(sizeof(char) * len);

	if (copy != NULL)
		DUPLIC_TE(copy, s, len);

	return (copy);
}

/**
 * MEAUSE_IT - ZZZZZZZZZZZZZZZZ
 * @s: ZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZ
 */
int MEAUSE_IT(const char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * NOT_SAM - ZZZZZZZZZZZZZZZZZ
 * @str: ZZZZZZZZZZZZZZZZ
 * @delim: ZZZZZZZZZZZZZZZZZZZ
 * Return: 1 ZZZZZZZZZZZZZZ
 */
int NOT_SAM(char str[], const char *delim)
{
	unsigned int i, j, k = 0;

	for (i = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	return ((i == k) ? 1 : 0);
}

/**
 * THROW_THEM - ZZZZZZZZZZZZZZZZZZZZ
 * @str: ZZZZZZZZZZZZZZZZ
 * @del: ZZZZZZZZZZZZZZZZZZZZZZZ.
 * Return: ZZZZZZZZZZZZZZZZZZZZZZZZ
 */
char *THROW_THEM(char str[], const char *del)
{
	char *current_char;
	unsigned int i, token_founded;
	static char *token_start, *token_end;

	if (str != NULL)
	{
		if (NOT_SAM(str, del))
			return (NULL);
		token_start = str;
		i = MEAUSE_IT(str);
		token_end = &str[i];
	}
	current_char = token_start;
	if (current_char == token_end)
		return (NULL);

	for (token_founded = 0; *token_start; token_start++)
	{
		if (token_start != current_char)
			if (*token_start && *(token_start - 1) == '\0')
				break;
		for (i = 0; del[i]; i++)
		{
			if (*token_start == del[i])
			{
				*token_start = '\0';
				if (token_start == current_char)
					current_char++;
				break;
			}
		}
		if (token_founded == 0 && *token_start)
			token_founded = 1;
	}
	if (token_founded == 0)
		return (NULL);
	return (current_char);
}

/**
 * ARENUMBERS - ZZZZZZZZZZZZZZZZ
 * @s: ZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
 */
int ARENUMBERS(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
		{
			return (0);
		}
	}
	return (1);
}
