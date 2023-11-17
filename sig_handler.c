#include "main.h"

/**
 * signal_handler - handles signals for ctrl c
 * @signal: signal number
 * Return: nothing
 */
void sig_handler(int signal)
{
	char *prompt = "\n$ ";

	(void)signal;

	write(1, prompt, _strlen(prompt));
	fflush(stdout);
}
