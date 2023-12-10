#include "main.h"

/**
 * read_user_input - ae
 * Return: char
 */

char *read_user_input(void)
{
	char *linptr = NULL;
	size_t n = 0;
	ssize_t nchars_read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, PROMPT_SUCCESS, 2);

	nchars_read = getline(&linptr, &n, stdin);
	if (nchars_read == -1)
	{
		free(linptr);
		return (NULL);
	}
	return (linptr);
}

/**
 * tokenize_input - ae
 * @input: pointer.
 * Return: char
 */

char **tokenize_input(char *input)
{
	char *token = NULL, *tmp = NULL, **command = NULL;
	int pt = 0, x = 0;

	if (!input)
		return (NULL);
	tmp = _strdup(input);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(input), input = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		pt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	command = malloc(sizeof(char *) * (pt + 1));
	if (!command)
	{
		free(input), input = NULL;
		return (NULL);
	}
	token = strtok(input, DELIM);
	while (token != NULL)
	{
		command[x] = _strdup(token);
		token = strtok(NULL, DELIM);
		x++;
	}
	free(input), input = NULL;
	command[x] = NULL;
	return (command);
}

/**
 * execute_command - Executes a command in a new process.
 * @command: An array of strings representing the command and its arguments.
 * @argv: An array of strings representing the program name and its arguments.
 * @idx: An array of strings representing the program name and its arguments.
 * Return: The exit status of the executed command.
 */

int execute_command(char **command, char **argv, int idx)
{
	char *actual_command = NULL;
	pid_t child_pid;
	int stat;

	actual_command = get_location(command[0]);
	if (!actual_command)
	{
		printError(argv[0], command[0], idx);
		free_2d_arr(command);
		return (127);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		/* Child Process */
		if (execve(actual_command, command, environ) == -1)
		{
			free(actual_command), actual_command = NULL;
			free_2d_arr(command);
		}
	}
	else
	{
		/* parent Process */
		/* Wait for the Child */
		waitpid(child_pid, &stat, 0);
		free_2d_arr(command);
		free(actual_command), actual_command = NULL;
	}
	return (WEXITSTATUS(stat));
}

