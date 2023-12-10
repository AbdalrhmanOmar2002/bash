#include "main.h"

/**
 * free_2d_arr - Frees memory allocated for a two-dimensional array of str.
 * @fre: A pointer to a pointer to strings (2D array).
 */

void free_2d_arr(char **fre)
{
	int i;

	if (!fre)
		return;

	for (i = 0; fre[i]; i++)
	{
		free(fre[i]);
	}
	free(fre);
}

/**
 * is_built_in - check
 * @command: A pointer to a pointer to strings.
 * Return: 0 or 1
 */

int is_built_in(char *command)
{
	char *builtin[] = {
		"exit", "env", "setenv",
		"cd", NULL};
	int i;

	for (i = 0; builtin[i]; i++)
	{
		if (_strcmp(command, builtin[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * handle_built_in - check
 * @command: A pointer to a pointer to strings (2D array).
 * @argv: A pointer to a pointer to strings (2D array).
 * @stat: A pointer to a pointer to strings (2D array).
 * @idx: A pointer to a pointer to strings (2D array).
 */

void handle_built_in(char **command, char **argv, int stat, int idx)
{
	(void)argv;
	(void)idx;

	if (_strcmp(command[0], "exit") == 0)
	{
		exit_shell(command, &stat);
	}
	else if (_strcmp(command[0], "env") == 0)
	{
		print_env(command, &stat);
	}
}
/**
 * print_env - check
 * @command: A pointer to a pointer to strings (2D array).
 * @status: A pointer to a pointer to strings (2D array).
 */

void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_2d_arr(command);
	(*status) = 0;
}

/**
 * exit_shell - check
 * @command: A pointer to a pointer to strings (2D array).
 * @status: A pointer to a pointer to strings (2D array).
 */

void exit_shell(char **command, int *status)
{
	free_2d_arr(command);
	exit(*status);
}
