#include "shell.h"

/**
 * my_strcmp - A function that compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if success, -1 if failed
 */
int my_strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL && s2 == NULL)
	{
		return (0);
	}
	else if (s1 == NULL)
	{
		return (-1);
	}
	else if (s2 == NULL)
	{
		return (1);
	}
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	if (*s1 < *s2)
		return (-1);
	else if (*s1 > *s2)
		return (1);
	return (0);
}

/**
 * my_strlen - A function that gets the length of a string
 * @s: string
 *
 *Return:length of the string
 */
size_t my_strlen(const char *s)
{
	size_t length = 0;

	if (s == NULL)
	{
		return (0);
	}
	while (*s)
	{
		length++;
		s++;
	}
	return (length);
}

/**
 * my_strdup - a function that duplicates a string
 * @s: string
 *
 * Return: duplicated string
 */
char *my_strdup(const char *s)
{
	char *dup;
	unsigned int i, j;

	if (s == NULL)
	{
		return (NULL);
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		;
	}
	dup = (char *) malloc(sizeof(char) * (i + 1));

	if (dup == NULL)
	{
		return (NULL);
	}
	for (j = 0; j <= i; j++)
		dup[j] =  s[j];

	return (dup);
}

/**
 * my_strcat - A function that contatenates two strings
 * @dest: string destination
 * @src: string source
 *
 *Return: destination
 */
char *my_strcat(char *dest, const char *src)
{
	char *dest_ptr = dest;
	const char *src_ptr = src;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	while (*dest_ptr != '\0')
	{
		dest_ptr++;
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
