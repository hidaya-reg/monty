#include "monty.h"
/**
 * is_integer - Check if a string is a valid integer.
 * @str: The string to check
 * Return: 1 if str is a valid integer, 0 otherwise
 */

int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
