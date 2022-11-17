#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg variables
 * Return: 0 on success
 */
int main(int ac, int *av)
{
	char *prompt = "(Eshell) $";
	char *linptr;
	size_t n = 0;

	printf("%s", prompt);
	getline(&linptr, &n, stdin);

	free(linptr);

	return (0);
}
