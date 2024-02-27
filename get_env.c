#include "shell.h"

/**
 * get_env - gets the enviroment variable
 *
 * @varia: ssd
 *
 * Return: 1 upon succes, 0 if no
 */

char *get_env(char *varia)
{
	char *tmp, *key, *env, *val;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = string_dup(environ[i]);
		key = strtok(tmp, "=");
		if (strcmp(key, varia) == 0)
		{
			val = strtok(NULL, "\n");
			env = string_dup(val);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
