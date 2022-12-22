#include "main.h"

/**
 * _getline - take user input from command line
 * @line: input string from command line
 * Return: void
 */
void _getline(char **line)
{
	ssize_t char_read;

	char_read = getline(line, BUFFER_SIZE, stdin);
	if (char_read == -1)
	{
		printf("\n");
		free(*line);
		exit(1);
	}
}
