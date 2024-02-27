#include "shell.h"

/**
 * free_array - frees the array given
 *
 * @arr:
 *
 * Return: 1 upon succes, 0 if no
 */

void free_array(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]), arr[i] = NULL;
	free(arr), arr = NULL;
}

/**
 *_itoa - frees the array given
 *
 * @n: the number
 *
 * Return: 1 upon succes, 0 if no
 */

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	Reverse_string(buffer, i);
	return (strdup(buffer));
}
/**
 * Reverse_string - reverses a string
 * @str : string
 * @len : the length
 */

void Reverse_string(char *str, int len)
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
/**
 * print_errors - print the error
 * @nm : name of the shell
 * @cmd : the command
 * @i : the number
 *
 */

void print_errors(char *nm, char *cmd, int i)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(i);

	write(STDERR_FILENO, nm, string_length(nm));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, string_length(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, string_length(cmd));
	write(STDERR_FILENO, mssg, string_length(mssg));

	free(index);
}
