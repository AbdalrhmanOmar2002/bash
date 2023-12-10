#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: char
 *
 * Return: 0.
 */

char *_strdup(char *str)
{
	char *m;
	int i = 0, size = 0;

	if (str == NULL)
		return (NULL);

	while (*str != '\0')
	{
		size++;
		str++;
	}
	str = str - size;
	m = malloc(sizeof(char) * (size + 1));
	if (m == NULL)
		return (NULL);
	for (i = 0; i <= size; i++)
	{
		m[i] = str[i];
	}

	return (m);
}

/**
 * _strcmp - a function that compares two strings
 *
 * @s1: string 1 input to compare
 * @s2: against this other string 2
 *
 * Return: 0 if s1 and s2 are equal
 *        negative integer if the stopping character
 *                in @s1 was less than the stopping
 *                character in @s2
 *        positive integer if the stopping character
 *                in @s1 was greater than the stopping
 *                character in @s2
 */

int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}

/**
 * _strlen - returns the length of a string
 *
 * @s: string parameter input
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	int counter;

	for (counter = 0; *s != '\0'; ++s)
		++counter;

	return (counter);
}

/**
 * _strcat - function that concatenates
 *          two strings.
 *
 * @dest: pointer to destnation input
 * @src: pointer to source input
 *
 * Return: pointer to resulting string @dest
 */

char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = *src;
	return (dest);
}

/**
 * _strcpy - copies a string from one pointer to another
 *	including the terminating null byte (\0)
 *
 * @src: source of string parameter input
 * @dest: destination of string
 *
 * Return: pointer to dest input parameter
 */

char *_strcpy(char *dest, char *src)
{
	int a, b = 0;

	for (a = 0; src[a] != '\0'; ++a)
	{
		dest[b] = src[a];
		++b;
	}
	dest[b] = '\0';

	return (dest);
}
