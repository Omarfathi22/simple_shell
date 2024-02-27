#include "shell.h"
/**
 * exit_shell - exits the shell
 * @cmd: command
 * @arg: arguments
 * @s: status
 * @i: index
 * Return: 0 on success.
 */
void exit_shell(char **cmd, char **arg, int *s, int i)
{
	int exit_val = 0;
	char *ind;
	char msg[] = ": exit: illegal number: ";

	if (*s)
		exit_val = *s;

	if (cmd[1])
	{
		if (positive_num(cmd[1]))
		{
			exit_val = _atoi(cmd[1]);
		}

		else
		{
			ind = _itoa(i);
			write(STDERR_FILENO, arg[0], string_length(arg[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, ind, string_length(ind));
			write(STDERR_FILENO, msg, string_length(msg));
			write(STDERR_FILENO, cmd[1], string_length(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(ind), ind = NULL;
			free_array(cmd);
			*s = 2;
			return;
		}
	}
	free_array(cmd);
	exit(exit_val);
}