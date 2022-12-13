#include "main.h"

int main(int ac, char **av)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t char_read;
	const char *delim = " \n";
	char *prompt = "$ ";
	char *token = NULL;
	char *token_args[30];
	pid_t pid;
	int status;
	int i = 0;

	while (1)
	{
		(void)ac;
		/* print a prompt */
		printf("%s", prompt);
		/* take input */
		char_read = getline(&lineptr, &n, stdin);
		if (char_read == -1) /* EOF, CTRL + D */
		{
			printf("Exiting shell\n");
			free(lineptr);
			exit(1);
		}
		pid = fork(); /* create fork */
		if (pid == 0)
		{
			token = strtok(lineptr, delim); /* split strings into words */

			while (token != NULL)
			{
				token_args[i] = token; /* token arguments */
				i++;

				token = strtok(NULL, delim); /* second string */
			}
			token_args[i] = NULL; /* add null character to end of argument */
			
			if (execve(token_args[0], token_args, NULL) < 0) /* execute commands */
			{
				perror(av[0]);
				exit(1);
			}
		}
		else if (pid > 0)
		{
			if (wait(&status) < 0)
			{
				perror("Error: wait failed\n");
				exit(1);
			}
		}
		else
		{
			perror("Error: fork failed");
			exit(1);
		}
	}
	free(lineptr);
	return (0);
}
