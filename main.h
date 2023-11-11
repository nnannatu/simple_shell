#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_SIZE 1024
#define MAX_TOKENZ 100

int _putchar(char m);
void _puts(char *word);
int _strlen(char *m);
char *find_cmd(const char *argv, const char *env);

#endif
