#include "regex.h"

/**
 * regex_match - checks whether a pattern matches a string
 * @str: string to scan
 * @pattern: regular expression pattern
 *
 * Return: 1 if the pattern matches the string, otherwise 0
 */
int regex_match(char const *str, char const *pattern)
{
	int first_match;

	if (*pattern == '\0')
		return (*str == '\0');

	first_match = (*str != '\0' &&
		       (*pattern == '.' || *pattern == *str));

	if (*(pattern + 1) == '*')
	{
		return (regex_match(str, pattern + 2) ||
			(first_match && regex_match(str + 1, pattern)));
	}

	return (first_match && regex_match(str + 1, pattern + 1));
}
