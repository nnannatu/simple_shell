#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @m: String to count
 *
 * Return: String length
 */
int _strlen(char *m)
{
	int n = 0;

	for (; *m != '\0'; m++)
	{
		n++;
	}

	return (n);
}
