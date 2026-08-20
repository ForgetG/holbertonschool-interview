#include "holberton.h"

/**
 * wildcmp - compares two strings, where s2 may contain '*'
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (wildcmp(s1, s2 + 1))
			return (1);

		if (*s1 != '\0')
			return (wildcmp(s1 + 1, s2));

		return (0);
	}

	if (*s1 == '\0' || *s2 == '\0')
		return (*s1 == *s2);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
