#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

typedef struct builtin_cmd
{
	char *cmd;
	int (*func)();
} builtin_cmd;


int _putchar(char c);
char **_strtow(char *str, char delim);
int _strlen(char *str);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *ch_path(char *cmd, char *path);
int gbin_func(char **arg, char **env);
int f_exit(char **arg);
int _strcmp(char *s1, char *s2);
int f_printenv(char **arg, char **env);
void full_path(char **argv, char **env);
int exe_syscmd(char **argv);
int exe_cmd(char *buf, char **env);
void cmd_sep(char *buf, char **env);
int _atoi(char *s);

#endif /* MAIN_H */
