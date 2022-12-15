#include "main.h"
/**
 * main - execute a simple shell
 * @ac: argument count
 * @av: argument vector
 * Return: Always 0.
 */
int main(__attribute__((unused))int ac, char **av)
{
	char *lineptr = NULL;
	char *token = NULL, *token_args[30];
	pid_t pid;
	size_t n = 0;
	int i = 0;

	while (1)
	{
		printf("$ "); /* prompt */
		if (getline(&lineptr, &n, stdin) < 0)
		{
			printf("\n");
			free(lineptr);
			exit(1);
		}
		pid = fork(); /* create fork */
		if (pid < 0)
		{
			perror("fork");
			exit(1);
		} else if (pid == 0)
		{
			token = strtok(lineptr, " \n"); /* split strings into words */
			while (token != NULL)
			{
				token_args[i] = token; /* token arguments */
				i++;
				token = strtok(NULL, " \n"); /* second string */
			} token_args[i] = NULL; /* add null character to end of argument */
			if (execve(token_args[0], token_args, NULL) < 0) /* execute commands */
			{
				perror(av[0]);
				exit(1);
			}

		}
		else
			wait(NULL);
	}
	free(lineptr);
	return (0);
}
