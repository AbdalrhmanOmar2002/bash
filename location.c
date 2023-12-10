#include "main.h"
/**
 * get_location - ae
 * @command: pointer
 * Return: char
 */

char *get_location(char *command)
{
	char *path_env, *full_cmd, *dir;
	struct stat st;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(command) + 2);
		if (full_cmd)
		{
			strcpy(full_cmd, dir);
			strcat(full_cmd, "/");
			strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			else
			{
				free(full_cmd), full_cmd = NULL;
				dir = strtok(NULL, ":");
			}
		}
	}
	free(path_env);
	return (NULL);
}

/**
 * _getenv - ae
 * @var: pointer
 * Return: char
 */

char *_getenv(char *var)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (key)
		{
			if (_strcmp(key, var) == 0)
			{
				value = strtok(NULL, "\n");
				env = _strdup(value);
				free(tmp);
				return (env);
			}
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
