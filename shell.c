#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg variables
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	char *prompt = "#asus $";
	char *linptr;
	size_t n = 0;

	(void)ac; (void)av;

	printf("%s", prompt);
	getline(&linptr, &n, stdin);
	printf("%s\n", linptr);

	free(linptr);

	return (0);
}
