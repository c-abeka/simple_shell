#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg variables
 * Return: 0 on success
 */
int main(void)
{
	char *full_cmd = NULL, *copy_cmd = NULL;
	char *prompt = "#asus $";
	char *linptr = NULL;
	size_t n = 0;
	ssize_t chars_read;
	char *token;
	const char *delimeter = " \n";
	char **av;
	int i = 0;
	int count_tokens = 0;

	/*print prompt*/
	printf("%s", prompt);
	chars_read = getline(&linptr, &n, stdin);

	copy_cmd = malloc(sizeof(char) * chars_read);
	if (copy_cmd == NULL)
	{
		perror("Memory allocation fault");
		return (-1);
	}
	strcpy(copy_cmd, full_cmd);

	if (chars_read == -1)
	{
		printf("Closing shell....\n");
		return (-1);
	}
	else
	{
		token = strtok(full_cmd, delimeter);

		while (token)
		{
			count_tokens++;
			token = strtok(NULL, delimeter);
		}
		count_tokens++;
		for (i = 0; token; i++)
		{
			/* code */
			av = malloc(sizeof(char *) * count_tokens);
			strcpy(av[i], token);

			token = strtok(NULL, delimeter);
		}

		av[i] = NULL;

		free(linptr);
		free(av);
		free(full_cmd);
		free(copy_cmd);
	}

	return (0);
}
