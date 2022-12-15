#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#endif /* _MAIN_H */
