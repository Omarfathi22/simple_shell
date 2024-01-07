#include "shell.h"

/**
* check_builtin_command - checks if the command is a buildin
* @arv: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*check_builtin_command(char **arv))(char **arv)
{
	int i, j;
	my_build T[] = {
		{"exit", _exitt},
		{"env", print_env},
		{"setenv", set_env},
		{"unsetenv", un_set_env},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		j = 0;
		if (T[i].name[j] == arv[0][j])
		{
			for (j = 0; arv[0][j]; j++)
			{
				if (T[i].name[j] != arv[0][j])
					break;
			}
			if (!arv[0][j])
				return (T[i].func);
		}
	}
	return (0);
}