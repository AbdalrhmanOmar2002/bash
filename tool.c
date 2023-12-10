#include "main.h"

/**
 * printError - Print error message to stderr.
 * @name: Name of the program.
 * @cmd: Command that was not found.
 * @idx: Index.
 */

void printError(char *name, char *cmd, int idx)
{
	char *index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": NOT FOUND\n", 12);

	free(index);
}

/**
 * _itoa - Convert integer to string.
 * @n: Integer to convert.
 * Return: String representation of the integer.
 */

char *_itoa(int n)
{
	char *result;
	char buffer[20];
	int i = 0;

	if (n == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	rev_str(buffer, i);
	result = _strdup(buffer);

	if (!result)
	{
		return (NULL);
	}

	return (result);
}

/**
 * rev_str - Reverse a string.
 * @str: String to reverse.
 * @len: Length of the string.
 */
void rev_str(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
