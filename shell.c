#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg variables
 * Return: 0 on success
 */
int main(int ac __attribute__((unused)), char **av)
{
	char *interface = "CAshell $ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	const char *delim = " \n";
	size_t n = 0;
	ssize_t chars_read;
	int i, token_count = 0;
	char *token;

	while (1)
	{
		printf("%s", interface);
		chars_read = getline(&lineptr, &n, stdin);
		lineptr_copy = malloc(sizeof(char) * chars_read);

		if (chars_read == -1)
		{
			printf("Terminating shell....\n");
			return (-1);
		}

		if (lineptr_copy == NULL)
		{
			perror(": : memory allocation error");
			return (-1);
		}
		strcpy(lineptr_copy, lineptr);

		token = strtok(lineptr_copy, lineptr);

		while (token)
		{
			token_count++;
			token = strtok(NULL, delim);
		}
		token_count++;

		av = malloc(sizeof(char *) * token_count);

		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			strcpy(av[i], token);
			token = strtok(NULL, delim);
		}
		av[i] = NULL;

		printf("%s\n", lineptr);

		free(lineptr);
	}

	return (0);
}
