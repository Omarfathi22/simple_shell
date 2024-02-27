#include "shell.h"

/**
 * execute_command - executes the line
 *
 * @args: the tokenised line
 * @argv : the name of the shell
 * @i : the iterator of the status
 * Return: 1 upon succes, 0 if no
 */

int execute_command(char **args, char **argv, int i)
{
	pid_t frk;
	int status;
	char *cmd;

	cmd = get_path(args[0]);
	if (!cmd)
	{
		free(cmd);
		print_errors(argv[0], args[0], i);
		free_array(args);
		exit(127);
	}

	frk = fork();
	if (frk == 0)
	{
		if (execve(cmd, args, environ) == -1)
		{
			free(cmd), cmd = NULL;
			free_array(args);
			exit(0);
		}
	}
	else
	{
		waitpid(frk, &status, 0);
		free_array(args);
		free(cmd);
	}
	return (WEXITSTATUS(status));
}