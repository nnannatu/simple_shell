#include "main.h"


/**
 * _strdup - duplicating string
 * @str: string to be duplicated
 * Return: string
 */
char *_strdup(const char *str)
{
	char *new_str = (char *)malloc(_strlen(str) + 1);
	size_t n = 0;

	if (new_str == NULL)
		return (NULL);

	for (; n < (_strlen(str) + 1); n++)
		new_str[n] = str[n];

	return (new_str);
}
