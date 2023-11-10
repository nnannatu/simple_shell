#include "main.h"

char *find_cmd(const char *argv, const char *env)
{
	if (env == NULL)
		return (NULL);

	if ((char *env_cpy = strdup(env)) == NULL)
		return (NULL);
	char *token = strtok(env_cpy, delim);
	char output = NULL;
	while (token != NULL)
	{
		if (strcmp(token, "/usr/local/bin" | "/usr/bin" | "/bin") == 0)
			strcpy(output, token);
			strcat(output, "/");
			strcat(output, argv);

		if (access(output, F_OK && X_OK) == 0)
		{
			free(env_cpy);
			return(strdup(output));
		}
		else
			perror("error");
			exit(-1);
		token = strtok(NULL, delim);
	}
	free(env_cpy);
	return(NULL);
}
