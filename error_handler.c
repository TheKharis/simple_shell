#include "main.h"

/**
 * _err - handle function errors
 * @str: error to be printed
 * @exit_num: return value of error
 * Return: void
 */
void _err(char *str, int exit_num)
{
	perror(str);
	exit(exit_num);
}
