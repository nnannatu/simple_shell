#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @m: String to count
 *
 * Return: String length
 */
size_t _strlen(const char *str)
{
	size_t n = 0;

	for (; *str != '\0'; str++)
	{
		n++;
	}

	return (n);
}
