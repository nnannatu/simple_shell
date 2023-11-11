#include "main.h"


char *find_cmd(const char *argv, const char *env);
int main(void)
{
	char *tokenz[MAX_TOKENZ];

	while (1)
	{
		char *input = NULL;
		size_t size;

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
			++num;
		}
		tokenz[num] = NULL;
		char *cd = "cd";

		if (num > 0)
		{
			if (strcmp(tokenz[0], "cd") == 0)
			{
				if (num == 2)
				{
					if (chdir(tokenz[1]) != 0)
						perror("chdir");
				}
				else if (num == 1)
				{
					const char *home = "/home/username";

					if (chdir(home) != 0)
						perror("chdir");
				}
				else
					perror("chdir");
			}
			else if (strcmp(tokenz[0], "exit") == 0)
			{
				free(input);
				exit(0);
			}
		}

		const char *path = "PATH";
		char *cmd = find_cmd(tokenz[0], path);

		if (cmd)
		{
			pid_t pid;

			pid = fork();
			if (pid < 0)
				perror("fork");
			else if (pid == 0)
			{
				execve(cmd, tokenz, __environ);
				perror("execve");
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
