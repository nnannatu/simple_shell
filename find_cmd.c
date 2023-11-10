#include "main.h"

char *find_cmd(const char *argv, const char *env)
{
	if (env == NULL)
		return (NULL);

	if ((char *env_cpy = strdup(env)) == NULL)
		return (NULL);
	if(strtok(env_cpy) == NULL)
		
}
