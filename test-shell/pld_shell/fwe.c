#include "main.h"

int main(void)
{
	/* set variable to hold command to execute */
	char *command[] = {"/usr/bin/ls", "-l", "/tmp", NULL};
	int status;
	int i;

	/* set a for loop to loop five times in child-process */
	for (i = 1; i <= 5; i++)
	{
		pid_t child_pid = fork(); /* create child process and fork */

		if (child_pid == 0)
		{
			if (execve(command[0], command, NULL) < 0) /* execute command if pid is succ */
			{
				perror("Error: execve failed\n"); /* if execve returns */
				exit(1);
			}
		}
		else if (child_pid > 0)
		{
			wait(&status); /* wait for child process to exit */
			if (status != 0)
			{
				printf("Error: child process exited with %d\n", status);
			}
		}
		else /* if fork fails */
		{
			perror("Error: fork failed");
			exit(1);
		}
	}
	return (0);
}
