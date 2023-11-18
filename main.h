#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TOKENZ 1024

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
int _unsetenv(const char *var);
int _setenv(const char *var, const char *value);
void sig_handler(int signo);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int is_builtin(char *cmd);
extern int (*builtin_func[])(char **);


#endif
