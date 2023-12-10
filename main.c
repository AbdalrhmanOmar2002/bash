#include "main.h"

/**
 * main - Entry point of the program.
 * @ac: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: The exit status of the program.
 */

int main(int ac, char **argv)
{
	char *linptr = NULL;
	char **command = NULL;
	int stat = 0, idx = 0;
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
		idx++;
		command = tokenize_input(linptr);
		if (!command)
			continue;

		if (is_built_in(command[0]))
		{
			handle_built_in(command, argv, stat, idx);
		}
		else
		{
			stat = execute_command(command, argv, idx);
		}
	}
}
