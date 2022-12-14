#include "main.h"
/**
 * main - build a simple shell
 * cannot handle short hand commands(ls)
 * @ac: Argument count
 * @av: Argument vector
 * Return: always 0
 */
int main(int ac, char **av)
{
	char *lineptr = NULL;
	size_t n = 0;
	char *prompt = "$ ";
	char *token = NULL;
	char *token_args[30];
	pid_t pid;
	int status, i = 0;

	while (1)
	{
		(void)ac;
		printf("%s", prompt); /* print a prompt */
		getline(&lineptr, &n, stdin);/* take input */
		if (getline == -1) /* EOF, CTRL + D */
		{
			printf("Exiting shell\n");
			free(lineptr);
			exit(1);
		}
		pid = fork(); /* create fork */
		if (pid == 0)
		{
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
	}
	free(lineptr);
	return (0);
}
