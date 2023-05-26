#include "shell.h"

/**
 * _realloc - reallocates memory to a string
 * @ptr: input pointer
 * @size: input size
 *
 *Return: reallocated string
 */
void *_realloc(void *ptr, size_t size)
{
	void *ptr_2 = malloc(size);

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		return (malloc(size));
	}

	if (ptr_2 != NULL)
	{
		_memcpy(ptr_2, ptr, size);
		free(ptr);
	}

	return (ptr_2);
}

/**
 * _memcpy - A function that copies memory
 * @dest: memory destination
 * @src: source memory
 * @num: number of bytes
 *Return: memory destination
 */
void *_memcpy(void *dest, const void *src, size_t num)
{
	char *dest_ptr = (char *)dest;
	const char *src_ptr = (const char *)src;
	size_t i;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	dest_ptr = (char *)dest;
	src_ptr = (const char *)src;

	if (dest_ptr > src_ptr && dest_ptr < src_ptr + num)
	{
		dest_ptr += num - 1;
		src_ptr += num - 1;

		for (i = 0; i < num; i++)
		{
			*dest_ptr = *src_ptr;

			dest_ptr--;
			src_ptr--;
		}
	}
	else
	{
		for (i = 0; i < num; i++)
		{
			*dest_ptr = *src_ptr;

			dest_ptr++;
			src_ptr++;
		}
	}

	return (dest);
}

/**
 * my_strcpy - a function that copies a string from source to destination
 * @dest: string destination
 * @src: string source
 *
 *Return: destination string
 */
char *my_strcpy(char *dest, const char *src)
{
	char *dest_ptr = dest;
	const char *src_ptr = src;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	while (*src_ptr != '\0')
	{
		*dest_ptr = *src_ptr;

		dest_ptr++;
		src_ptr++;
	}

	*dest_ptr = '\0';

	return (dest);
}

/**
 * my_strncmp - a function that compares n bytes etween two strings
 * @s1: first string
 * @s2: second string
 * @num: number of bytes
 *
 * Return: 0 if success, -1 if failure
 */
int my_strncmp(const char *s1, const char *s2, size_t num)
{
	if (s1 == NULL || s2 == NULL)
	{
		return (-1);
	}

	while (num > 0 && (*s1 || *s2))
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		num--;
	}

	return (0);
}
