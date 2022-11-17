#include <stdio.h>

/**
 * _strlen - entry point
 * @s: the string
 * Return: string length
 */
int _strlen(char *s)
{
	int len = 0;

	while(s[len])
		len++;

	return (len);
}
