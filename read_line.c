#include "shell.h"

/**
 * Read_command_line - reads the current line
 *
 * Return: the line
 */

char *Read_command_line()
{
	char *lne = NULL;
	size_t n = 0;
	ssize_t line;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	line = getline(&lne, &n, stdin);
	if (line < 0)
	{
		free(lne);
		return (NULL);
	}
	return (lne);
}