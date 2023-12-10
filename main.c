#include "main.h"

/**
 * main - Entry point of the program.
 * @ac: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * @env: Array of environment variable strings.
 * Return: The exit status of the program.
 */

int main(int ac, char **argv, char **env)
{
	char *linptr = NULL;
	char **command = NULL;
	int stat = 0;
	(void)ac;

	while (1)
	{
		linptr = read_user_input();

		if (linptr == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}

			return (stat);
		}

		command = tokenize_input(linptr);
		if (!command)
			continue;

		stat = execute_command(command, argv, env);
	}
	return (0);
}
