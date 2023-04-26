#include "shell.h"

/**
 * interactive - check if the shell is in interactive mode
 * @info: struct containing shell information
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= STDERR_FILENO);
}

/**
 * is_delim - checks if character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim != '\0')
{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _isalpha - checks if a character is alphabetic
 * @c: the character to check
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the converted number, or 0 if no numbers in string
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		} else if (flag == 1)
{
			flag = 2;
		}
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
