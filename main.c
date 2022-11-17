#include <stdio.h>

/**
 * main - entry point
 * @ac: argument count
 * @av: the variables
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	int i = 0;

	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
