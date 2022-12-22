#include "main.h"

/**
 * print_env - env builtin that prints current environment
 *
 * Return: void
 */
void print_env(void)
{
	char **env; /* variables to store environ and name, value keys */
	/* iterate through all env variables */
	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}
