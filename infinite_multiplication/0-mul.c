#include "holberton.h"
#include <stdlib.h>

/**
 * print_error - Prints Error and exits with status 98
 */
void print_error(void)
{
	char *error = "Error\n";
	int i;

	for (i = 0; error[i]; i++)
		_putchar(error[i]);

	exit(98);
}

/**
 * str_len - Returns the length of a string
 * @str: String to measure
 *
 * Return: Length of the string
 */
int str_len(char *str)
{
	int len = 0;

	while (str[len])
		len++;

	return (len);
}

/**
 * is_number - Checks if a string contains only digits
 * @str: String to check
 *
 * Return: 1 if valid, 0 otherwise
 */
int is_number(char *str)
{
	int i;

	if (!str || !str[0])
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * multiply - Multiplies two positive integer strings
 * @num1: First number
 * @num2: Second number
 * @result: Array used to store the result
 * @len2: Length of second number
 */
void multiply(char *num1, char *num2, int *result, int len2)
{
	int i, j, len1;
	int product, sum;

	len1 = str_len(num1);

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			product = (num1[i] - '0') * (num2[j] - '0');
			sum = product + result[i + j + 1];

			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}
}

/**
 * print_result - Prints the multiplication result
 * @result: Array containing the result
 * @size: Size of the array
 */
void print_result(int *result, int size)
{
	int i = 0;

	while (i < size - 1 && result[i] == 0)
		i++;

	while (i < size)
		_putchar(result[i++] + '0');

	_putchar('\n');
}

/**
 * main - Multiplies two positive numbers of arbitrary size
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int len1, len2, size, i;
	int *result;

	if (argc != 3)
		print_error();

	if (!is_number(argv[1]) || !is_number(argv[2]))
		print_error();

	len1 = str_len(argv[1]);
	len2 = str_len(argv[2]);
	size = len1 + len2;

	result = malloc(sizeof(int) * size);
	if (!result)
		print_error();

	for (i = 0; i < size; i++)
		result[i] = 0;

	multiply(argv[1], argv[2], result, len2);
	print_result(result, size);

	free(result);
	return (0);
}
