#include "shell.h"
/**
 * print_environment - prints the environment variables
 *
 * @cmd: command.
 * @s: status
 * Return: nothing.
 */
void print_environment(char **cmd, int *s)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], string_length(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_array(cmd);
	(*s) = 0;
}