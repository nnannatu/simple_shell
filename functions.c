#include "main.h"

size_t i;

int lsh_cd(char **args)
{
	if (args[1] == NULL)
		write(2, "lsh: cd: missing argument\n", 26);
	else
	{
		if (chdir(args[1]) != 0)
			perror("lsh");
	}
	return (1);
}


int lsh_help(char **args __attribute__((unused)))
{
	write(1, "Simple Shell\n", 13);
	write(1, "Built-in commands: cd, help, exit\n", 34);
	return (1);
}


int lsh_exit(char **args __attribute__((unused)))
{
	return (0);
}

int (*builtin_func[])(char **) = {&lsh_cd, &lsh_help, &lsh_exit};

int is_builtin(char *tokenz)
{
	for (i = 0; i < sizeof(builtin_func) / sizeof(builtin_func[0]); i++)
	{
		if (_strcmp(tokenz, "exit") == 0)
			return (1);
		if (_strcmp(tokenz, "cd") == 0 || _strcmp(tokenz, "help") == 0)
			return (1);
	}
	return (0);
}
