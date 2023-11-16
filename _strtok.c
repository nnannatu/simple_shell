#include "main.h"

/**
 * _strtok - function to tokenize a string.
 * @str: the string to be tokenized.
 * @delim: the symbol of separation.
 * Return: the point to the token.
 */

char *_strtok(char *str, const char *delim)
{
	static char *ptr;
	char *token = NULL;
	char *buffer = NULL;

	if (str == NULL)
		str = ptr;

	if (str == NULL)
		return (NULL);

	buffer = malloc(_strlen(str) + 1);
	if (buffer == NULL)
		return (NULL);

	_strcpy(buffer, str);

	token = buffer;

	while (*buffer != '\0')
	{
		if (strchr(delim, *buffer) != NULL)
		{
			*buffer = '\0';
			buffer++;
			break;
		}
		buffer++;
	}

	ptr = buffer;
	free(buffer);
	return (token);
}
