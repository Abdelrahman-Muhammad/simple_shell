#include "shell.h"

/**
 * DUPLIC_TE - ZZZZZZZZZZZZ
 * @newptr: ZZZZZZZZZZZZ
 * @ptr: ZZZZZZZZZZZZ
 * @size: ZZZZZZZZZZZZ
 */
void DUPLIC_TE(void *newptr, const void *ptr, unsigned int size)
{
	unsigned int i;
	char *dest = (char *)newptr;
	const char *src = (const char *)ptr;

	for (i = 0; i < size; i++)
		dest[i] = src[i];
}

/**
 * REELOCK - ZZZZZZZZZZZZ
 * @ptr: ZZZZZZZZZZZZ
 * @old_size: ZZZZZZZZZZZZ.
 * @new_size: ZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZ
 */
void *REELOCK(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;
	unsigned int i;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (ptr == NULL)
	{
		return (newptr);
	}
	else
	{
		char *p = ptr, *np = newptr;

		for (i = 0; i < old_size; i++)
			np[i] = p[i];

		free(ptr);
	}
	return (newptr);
}

/**
 * REELOCKAGN - ZZZZZZZZZZZZZZZZ
 * @ptr: ZZZZZZZZZZZZZZZZ
 * @old_size: ZZZZZZZZZZZZZZ
 * @new_size: ZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZZZ
 */
char **REELOCKAGN(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (new_size == 0)
	{
		for (i = 0; i < old_size; i++)
			free(ptr[i]);
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		newptr = malloc(sizeof(char *) * new_size);
		if (newptr == NULL)
			return (NULL);
		for (i = 0; i < new_size; i++)
			newptr[i] = NULL;
		return (newptr);
	}
	if (new_size == old_size)
		return (ptr);
	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
	{
		for (i = 0; i < old_size; i++)
			free(ptr[i]);
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];
	for (i = old_size; i < new_size; i++)
		newptr[i] = NULL;
	free(ptr);
	return (newptr);
}

/**
 * TNMC_MER - ZZZZZZZZZZZZZZZZZ
 * @in: ZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZ
 */
char *TNMC_MER(char *in)
{
	int i, j;
	char *out = in;

	for (i = 0, j = 0; in[i] != '\0'; i++)
	{
		if (in[i] == '#' && (i == 0 || in[i - 1] == '\n' ||
							 in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';'))
		{
			while (in[i] != '\n' && in[i] != '\0')
				i++;
		}
		else
		{
			out[j++] = in[i];
		}
	}

	out[j] = '\0';

	return (out);
}

/**
 * MAIN_APP - ZZZZZZZZZZZZZZZZZZZ
 * @my_info: ZZZZZZZZZZZZZZZ
 */
void MAIN_APP(shell_my_info_t *my_info)
{
	char *input;
	int loop = 1, i_eof;

	while (loop)
	{
		write(STDIN_FILENO, "~ bash: ", 8);
		input = GET_BUFFER_LN(&i_eof);
		if (i_eof != -1)
		{
			input = TNMC_MER(input);
			if (input == NULL)
				continue;

			if (ERORR_CHK(my_info, input))
			{
				my_info->status = 2;
				continue;
			}
			input = CHNAG_THEM(input, my_info);
			loop = DIVIDE_ITOP(my_info, input);
			my_info->counter++;
		}
		else
		{
			loop = 0;
		}
		free(input);
	}
}
