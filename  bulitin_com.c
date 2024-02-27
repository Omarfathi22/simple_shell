#include "shell.h"
/**
 * if_builtin_command - checks if the cmd is built- in command
 * @cmd: command
 * Return: if the cmd is found in the list returns 1
 * otherwise, it retuns 0
 */

int if_builtin_command(char *cmd)
{
	char *buil[] = {
		"exit", "env", NULL};
	int i;

	for (i = 0; buil[i]; i++)
	{
		if (strcmp(cmd, buil[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * handle_builtin - determines the type of build-in
 * and invokes corresponding handling functions
 * @cmd: command
 * @arg: arguments
 * @s: status
 * @i: index
 * Return: nothing.
 */
void handle_builtin(char **cmd, char **arg, int *s, int i)
{
	if (strcmp(cmd[0], "exit") == 0)
		exit_shell(cmd, arg, s, i);
	else if (strcmp(cmd[0], "env") == 0)
		print_environment(cmd, s);
}