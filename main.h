#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64
#define MAX_PATH_SIZE 256
#define MAX_TOKENZ 100

extern char **environ;
int _putchar(char m);
void _puts(char *word);
int _strlen(char *m);
char *find_cmd(const char *tokenz);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *find_cmd(const char *tokenz);
char *_getenv(const char *name);
void execute_command(char **args);
int parse_input(char *input, char **args);
void free_args(char **args, int argc);
int resolve_command_path(char *command, char *full_path);
int tokenize_input(char *input, char **args);

#endif
