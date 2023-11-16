#include "main.h"

/**
 * _getline - custom getline function
 * @line: line buffer
 * @len: length of buffer
 * @stream: stream to read from
 * Return: number of characters read or -1 if fail
 */
ssize_t _getline(char **line, size_t *len, FILE *stream)
{

	ssize_t Read;
	size_t i;

	if (*line == NULL || *len == 0)
	{
		*len = 1024;
		*line = malloc(*len);

		if (*line == NULL)
			return (-1);
	}

	for (i = 0; i < *len; i++)
	{
		Read = read(fileno(stream), *line + i, 1);
		if (Read == 0)
		{
			if (i == 0)
				return (-1);
			else if (i != 0)
				break;
		}
		else if (Read == -1)
			return (-1);
		else if ((*line)[i] == '\n')
			break;
	}

	(*line)[i] = '\0';

	return (i);
}
