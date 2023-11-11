#include "main.h"

char *find_cmd(const char *argv, const char *env)
{
	if (env == NULL)
		return (NULL);
	char *env_cpy;

	if ((env_cpy = strdup(env)) == NULL)
		return (NULL);

	char *delim = " :";
	char *token = strtok(env_cpy, delim);
	char *output = NULL;

	while (token != NULL)
	{
		output = malloc(strlen(token) + strlen(argv) + 2);
		if (output == NULL)
		{
			free(env_cpy);
			return(NULL);
		}

		if (strcmp(token, "/usr/local/bin") == 0 || strcmp(token, "/usr/bin") == 0 || strcmp(token, "/bin") == 0)
		{
			strcpy(output, token);
			strcat(output, "/");
			strcat(output, argv);

			if (access(output, X_OK) == 0)
			{
				free(env_cpy);
				return(strdup(output));
			}
		}
		else
		{
			perror("error");
			exit(-1);
		}

		free(output);
		token = strtok(NULL, delim);
	}
	free(env_cpy);
	return(NULL);
}
