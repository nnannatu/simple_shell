#include "main.h"

/**
 *_getenv - function to source for
 *the external variable.
 *
 *@name: this is the name of the variable.
 *Return: NULL on success.
 */

char *_getenv(const char *name)
{
	int i = 0;
	char **env;
	char *env_cpy;

	if (name == NULL || environ == NULL)
		return (NULL);

	for  (env = environ; *env != NULL; env++)
	{
		env_cpy = *env;

		for (i = 0; strncmp(name, env_cpy, i) == 0; i++)
		{
			if (name[i] == '\0' && env_cpy[i] == '=')
				return (env_cpy + i + 1);
		}
	}
	return (NULL);
}
