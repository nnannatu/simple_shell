#include "main.h"

/**
 * _strncmp - compares n number of characters in a string
 * @str1: the first string.
 * @str2: the second string.
 * @n: the number of characters to compare.
 * Return: the number of compared characters
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; ++i)
	{
		if (str1[i] != str2[i])
		{
			return ((int)(str1[i] - str2[i]));
		}

		if (str1[i] == '\0' || str2[i] == '\0')
		{
			break;
		}
	}
	return (0);
}
