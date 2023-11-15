#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @m: String to count
 *
 * Return: String length
 */
int _strlen(const char *str)
{
	int n = 0;

	for (; *str != '\0'; str++)
	{
		n++;
	}

	return (n);
}
