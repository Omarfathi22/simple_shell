#include "shell.h"
/**
 * string_length - returns the length of a string
 * @s: the string whose length to check
 * Return: integer length of string
 */

int string_length(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}
/**
 * string_cat - concatenates two strings
 * @destination: the destination buffer
 * @source: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *string_cat(char *destination, char *source)
{
	char *r = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (r);
}

/**
 * string_cop - copies a string
 * @destination: the destination
 * @source: the source
 *
 * Return: pointer to destination
 */
char *string_coy(char *destination, char *source)
{
	int i = 0;

	if (destination == source || source == 0)
		return (destination);
	while (source[i])
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return (destination);
}
