#include "main.h"

/**
 * exit_env - exit from shell or print the env
 * @line: input from command line
 * @line_copy: duplicate of string input
 * @str: input string
 * Return: void
 */
void exit_env(char *str, char *line, char *line_copy)
{
	if (strcmp(str, "exit") == 0) /* exit */
	{
		free(line);
		free(line_copy);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(str, "env") == 0) /* print env vars */
	{
		print_env();
	}
}

