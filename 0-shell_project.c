#include "main.h"

int main(void)
{
	char *tokenz[MAX_TOKENZ];

	while (1)
	{
		char *input = NULL;
		size_t size;

		printf("Eshell $ ");

		if (getline(&input, &size, stdin) == -1)
			break;
		{
			size_t len = strlen(input);

			if (input[len - 1] == '\n')
				input[len - 1] = '\0';
		}

		int num = 1;
		char *token = strtok(input, " ");

		while (token != NULL)
		{
			tokenz[num] = token;
			printf("%s\n", token);
			token = strok(NULL, " ");
			num++;
		}
		tokenz[num] = NULL;

		free(input);
	}
	return (0);
}
