#include "shell.h"

/**
 * RANDOM_IT- ZZZZZZZZZZZZZ
 * @s: ZZZZZZZZZZZZZZZ
 */
void RANDOM_IT(char *s)
{
	int i, len = MEAUSE_IT(s);
	char temp;

	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}
