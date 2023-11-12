#include "main.h"


char *find_cmd(const char *argv, const char *env);
int main(void)
{
	char *tokenz[MAX_TOKENZ];
	extern char **environ;
	while (1)
	{
		char *input = NULL;
		size_t size;
		const char *home = NULL;
		printf("Eshell $ ");

		if (getline(&input, &size, stdin) == -1)
			return(1);
		else
		{
			size_t len = strlen(input);

			if (input[len - 1] == '\n')
				input[len - 1] = '\0';
		}

		char *delim = " ";
		int num = 0;
		char *token = strtok(input, delim);

		while (token != NULL && num < MAX_TOKENZ - 1)
		{
			tokenz[num] = token;
			printf("%s\n", token);
			token = strtok(NULL, delim);
			num++;
		}
		tokenz[num] = NULL;

		if (num < 2)
		{
			write(2, "No command\n", 11);
		}
		if (strcmp(tokenz[1], "cd") == 0)
		{
			if (num == 2)
			{
				home = _getenv("HOME");
				if (home == NULL)
				{
					perror("getenv");
					return (1);
				}
				if (chdir(home) != 0)
				{
					perror("chdir");
					return (1);
				}
			}
			else if (num == 3)
			{
				if (chdir(tokenz[2]) != 0)
				{
					perror("chdir");
					return (1);
				}
			}
			else
			{
				write(2, "No command\n", 11);
				return (1);
			}	
		}
		else if (strcmp(tokenz[1], "exit") == 0)
		{
			if (num == 2)
				exit(0);
			else
				write(2, "No command\n", 11);
		}

		else
		{
			pid_t pid;

			pid = fork();
			if (pid == -1)
			{
				free(cmd);
				perror("fork");
				return(-1);
			}
			else if (pid == 0)
			{
				char *cmd = find_cmd(tokenz);
				if (cmd != NULL)
				{
					execve(cmd, tokenz, environ);
					perror("execve");
				}
			}
			else
			{
				int status;

				wait(&status);
			}
			free(cmd);
		}
		else
			return (1);
		free(input);
	}
	return (0);
}
