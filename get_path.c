#include "shell.h"

/**
 * get_path - Get the full path of a cmd
 * @cmd: The cmd
 * freearr - frees the array given
 * @arr:
 * Return: 1 upon succes, 0 if no
 */

char *get_path(char *cmd)
{
	char *pth, *dir, *fullcmd;
	int i;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
			{
				return (string_dup(cmd));
			}
			return (NULL);
		}
	}
	pth = get_env("PATH");
	if (!pth)
		return (NULL);
	dir = strtok(pth, ":");
	while (dir)
	{
		fullcmd = malloc(string_length(dir) + string_length(cmd) + 2);
		if (fullcmd)
		{
			 string_coy(fullcmd, dir);
			 string_cat(fullcmd, "/");
			 string_cat(fullcmd, cmd);
			if (stat(fullcmd, &st) == 0)
			{
				free(pth);
				return (fullcmd);
			}
			free(fullcmd), fullcmd = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(pth);
	return (NULL);
}