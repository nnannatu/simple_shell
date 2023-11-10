#include "main.h"

/**
 * _puts - Prints a string
 * @word: The string to print
 *
 * Return: void
 */
void _puts(char *word)
{
	while (*word != '\0')
	{
		_putchar(*word);
		word++;
	}
}
