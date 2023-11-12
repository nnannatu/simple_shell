#include "main.h"

char *_getenv(const char *name)
{
	int i = 0;
	char **env = NULL;
	char *env_cpy = NULL;
	if (name == NULL || environ == NULL)
		return (NULL);

	for  (*env = environ; *env != NULL; env++)
	{
		env_cpy = *env;

		for (i = 0; name[i] != '\0' && env_cpy[i] == name[i]; i++)

		if (name[i] == '\0' && env_cpy[i] == '=')
			return (env_cpy + i + 1);
	}
	return (NULL);
}
