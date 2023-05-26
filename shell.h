#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <limits.h>
#include <ctype.h>

int ch_dir(char **args);
int printenv(char **args);
int _exitt(char **args);
void update_dir(char *pwd);
int _unsetenv(char **args);
int _setenv(char **args);
int builtin_handler(char **args);
extern char **environ;
void _prompt(int argc, char **argv);
char *read_input();
void free_args(char **argv);
void signal_handler(int signum);
int process(char **args);
int execute(int ac, char **args);
char **tokenize(char *buffer, char *delim);
char *_strtok(char *str, char *delim);
char *_strstr(char *haystack, char *needle);
char *_getenv(const char *name);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *path_handler(char **argv);
int my_strcmp(const char *s1, const char *s2);
size_t my_strlen(const char *s);
char *my_strdup(const char *s);
void *_realloc(void *ptr, size_t size);
void *_memcpy(void *dest, const void *src, size_t num);
int my_isspace(char c);
char *my_strcpy(char *dest, const char *src);
char *my_strcat(char *dest, const char *src);
int my_strncmp(const char *s1, const char *s2, size_t num);

#endif
