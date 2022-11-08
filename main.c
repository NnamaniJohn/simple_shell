#include "main.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

/**
 * full_path - get full path of a command
 * @argv: command
 * @env: env
 * Return: void
 */

void full_path(char **argv, char **env)
{
	int i = 0;
	char *path;

	while (env[i] != NULL)
	{
		path = ch_path(argv[0], env[i]);
		if (path)
			break;
		i++;
	}
	if (path)
		argv[0] = path;
}

/**
 * main - a simple shell program
 * Return: 1 or 0;
 */

int main(int ac, char **av, char **env)
{
	char *buf = NULL;
	char **argv;
	size_t x = 0, n = 8;
	pid_t child_pid;
	int status, cont;
	struct stat sb;

	if (ac || av)
	{
	}

	while (1)
	{
		_putchar('$');
		_putchar(' ');
		_putchar(-1);

		x = getline(&buf, &n, stdin);
		if ((buf)[x - 1] == '\n')
			(buf)[x - 1] = '\0';
		argv = _strtow(buf, ' ');

		cont = gbin_func(argv, env);
		if (cont == 0)
			continue;
		/*if (_strcmp(argv[0], "exit") == 0)
			gbin_func(argv[0]);
		*/
		full_path(argv, env);
		if (stat(argv[0], &sb) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				return (1);
			}
			if (child_pid == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					printf("ok\n");
					perror("Error");
				}
			}
			else
			{
				wait(&status);
			}
		}
		else
		{
			perror("Error");
		}

	}
	return (0);
}
