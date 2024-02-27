#include "shell.h"

/**
 * main - the main function
 *
 * @ac: the int
 * @argv : the name of the shell
 *
 * Return: 1 upon succes, 0 if no
 */

int main(int ac, char **argv)
{
	char *line = NULL;
	char **cmd = NULL;
	int status = 0, i = 0;

	(void)ac;

	while (1)
	{
		line = Read_command_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		i++;
		cmd = tokenize_command(line);
		if (!cmd)
			continue;
		if (if_builtin_command(cmd[0]))
			handle_builtin(cmd, argv, &status, i);
		else
			status = execute_command(cmd, argv, i);
	}
	return (WEXITSTATUS(status));
}
