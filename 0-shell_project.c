#include "main.h"

char *find_cmd(const char *tokenz);

/**
 *main - a custom simple shell project.
 *no argument passed.
 *Return: zero on success.
 */


int main(void)
{
	char *tokenz[MAX_TOKENZ];
	char *cmd = NULL;
	char *delim;
	int num = 0;
	char *token;
	char *input = NULL;
	int status;
	size_t len;
	size_t size;
	const char *home;
	char *prompt = "shell $ ";

	while (1)
	{

		if (isatty(STDIN_FILENO))
			write(1, prompt, 9);

		if (getline(&input, &size, stdin) == -1)
		{	perror("getline");
			return (-1);
		}
		else
		{
			len = strlen(input);

			if (input[len - 1] == '\n')
				input[len - 1] = '\0';
		}

		delim = " ";
		num = 0;
		token = strtok(input, delim);

		while (token != NULL && num < MAX_TOKENZ - 1)
		{
			tokenz[num] = token;
			token = strtok(NULL, delim);
			num++;
		}
		tokenz[num] = NULL;

		if (num < 1)
		{
			write(2, "No command\n", 11);
			continue;
		}
		if (strcmp(tokenz[0], "cd") == 0)
		{
			if (tokenz[1] == NULL)
			{
				home = _getenv("HOME");
				if (home == NULL)
				{
					perror("getenv");
					return (-1);
				}

				if (chdir(home) != 0)
				{
					perror("chdir");
					return (-1);
				}
			}
			else
			{
				if (chdir(tokenz[1]) != 0)
				{
					perror("chdir");
					exit(1);
				}
			}
		}

		else if ((strcmp(tokenz[0], "exit") == 0) || (strcmp(tokenz[0], "EOF") == 0))
		{
			if (num == 1)
			{
				free(input);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("exit");
				exit(status);
			}
		}

		else
		{
			pid_t pid;

			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				return (-1);
			}
			else if (pid == 0)
			{
				cmd = find_cmd(tokenz[0]);
				if (cmd != NULL)
				{
					execve(cmd, tokenz, environ);
					perror("execve");
					free(cmd);
					exit(1);
				}
				free(cmd);
			}
			else
			{
				waitpid(pid, &status, 0);

				if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
				{
					perror("wait");
					return (-1);
				}
			}
		}
	}
	free(input);
	return (0);
}
