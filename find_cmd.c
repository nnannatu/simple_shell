#include "main.h"

/**
 * signal_handler - handles signals for ctrl c
 * @signal: signal number
 * Return: nothing
 */
void sig_handler(int signo)
{
	if (signo == SIGINT)
		write(1, "\n", 1);
}

/**
 *find_cmd -  A funcion to get the path
 *of the command passed.
 *
 *@tokenz: an array of tokenized commands.
 *Return: a pointer to the path of the command.
 */




char *find_cmd(char *tokenz);

char *find_cmd(char *tokenz)
{
	char *env = _getenv("PATH");
	char *env_cpy = NULL;
	char *token = NULL;
	char *output = NULL;

	if (env == NULL)
	{
		perror("_getenv");
		return (NULL);
	}
	env_cpy = _strdup(env);

	if (env_cpy == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	token = strtok(env_cpy, ":");
	while (token != NULL)
	{
		output = malloc(_strlen(token) + _strlen(tokenz) + 2);
		if (output == NULL)
		{
			perror("malloc");
			free(env_cpy);
			return (NULL);
		}

		_strcpy(output, token);
		_strcat(output, "/");
		_strcat(output, tokenz);

		if (access(output, X_OK) == 0)
		{
			free(env_cpy);
			return (output);
		}

		free(output);
		token = strtok(NULL, ":");
	}
	free(env_cpy);
	return (NULL);
}
