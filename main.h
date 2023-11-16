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

extern char **environ;
int _putchar(char m);
void _puts(char *word);
size_t _strlen(const char *str);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(const char *str_one, const char *str_two);
char *find_cmd(char *tokenz);
char *_getenv(const char *name);
int _strncmp(const char *str1, const char *str2, size_t n);
ssize_t _getline(char **line, size_t *len, FILE *stream);
char *_strtok(char *str, const char *delim);
const char *_strchr(const char *s, char c);

#endif
