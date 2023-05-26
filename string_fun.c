#include "shell.h"

/**
 * OLDONE - ZZZZZZZZZZZZZZZZZ
 * @des: ZZZZZZZZZZZZZZ
 * @src: ZZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZZZZ
 */
char *OLDONE(char *des, const char *src)
{
	char *ptr = des;

	while (*ptr != '\0')
		ptr++;
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';

	return (des);
}
/**
 * *OLDANOONE - ZZZZZZZZZZZZZZZZ
 * @des: ZZZZZZZZZZZ
 * @src: ZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZ
 */
char *OLDANOONE(char *des, char *src)
{

	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		des[i] = src[i];

	des[i] = '\0';

	return (des);
}
/**
 * ARESAMEA - ZZZZZZZZZZZZZZZZZZZZZ
 * @s1: ZZZZZZZZZZZZZZZZZZZZZ
 * @s2: ZZZZZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZ
 */
int ARESAMEA(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return ((*s1 > *s2) ? 1 : -1);
		}
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (0);
	}
	return ((*s1 == '\0') ? -1 : 1);
}
/**
 * ARESAMEAAA - ZZZZZZZZZZZZZZZZZZZZZZ
 * @s: ZZZZZZZZZZZZZZZZZ
 * @c: ZZZZZZZZZZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZZZZ
 */
char *ARESAMEAAA(char *s, char c)
{
	while (*s != '\0' && *s != c)
		s++;

	return ((*s == c) ? s : NULL);
}
/**
 * SPOOON - ZZZZZZZZZZZZZZZZZZZ
 * @s: ZZZZZZZZZZZZZZZZZZZZ
 * @s2: ZZZZZZZZZZZZZZZZZZZ
 * Return: ZZZZZZZZZZZZZZZZZZZZZZZ
 */
int SPOOON(char *s, char *s2)
{
	int i, j, found;

	for (i = 0; s[i] != '\0'; i++)
	{
		found = 0;
		for (j = 0; s2[j] != '\0'; j++)
		{
			if (s[i] == s2[j])
			{
				found = 1;
				break;
			}
		}
		if (found == 0)
			return (i);
	}
	return (i);
}
