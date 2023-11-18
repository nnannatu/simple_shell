#include "main.h"

char *find_cmd(char *tokenz);

/**
 *main - a custom simple shell project.
 *no argument passed.
 *Return: zero on success.
 */


int main(void)
{
	char *tokenz[MAX_TOKENZ];
	char *cmd = NULL;
	int num = 0;
	char *token;
	char *input = NULL;
	size_t len;
	size_t size;

	signal(SIGINT, sig_handler);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);

		if (_getline(&input, &size, stdin) == EOF || input == NULL)
		{
			perror("getline");
			free(input);
			return (1);
		}


		len = _strlen(input);

		if (input[len - 1] == '\n')
			input[len - 1] = '\0';

		if (_strcmp(input, "exit") == 0)
		{
			free(input);
			exit(0);
		}


		/* Tokenization */
		num = 0;
		token = strtok(input, " ");

		while (token != NULL && num < MAX_TOKENZ - 1)
		{
			tokenz[num] = token;
			token = strtok(NULL, " ");
			num++;
		}
		tokenz[num] = NULL;

		if (num < 1)
		{
			write(2, "No command\n", 11);
			continue;
		}

		if (is_builtin(tokenz[0]))
		{
			/* Execute built-in command */
			int result = (*builtin_func[0])(tokenz);
			if (result == 0)
			{
				free(input);
				exit(0);
			}
		}

		else
		{
			/* Execute external command */
			if (tokenz[0][0] == '/')
				cmd = tokenz[0];
			else
				cmd = find_cmd(tokenz[0]);

			if (cmd != NULL)
			{
				pid_t pid;

				pid = fork();
				if (pid == -1)
				{
					perror("fork");
					return (1);
				}
				else if (pid == 0)
				{
					/* Child process */
					execve(cmd, tokenz, NULL);
					perror("execve");
					free(input);
					exit(1);
				}

				else
				{
					/* Parent process */
					waitpid(pid, NULL, 0);
				}
			}
			else 
			{
				/* Command not found */
				write(2, "Command not found\n", 18);
			}
		}
	}
	free(input);
	return (0);
}
