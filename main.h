#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \n"

/* execute PATH */
char *search_path(const char *command);

#endif /* _MAIN_H */
