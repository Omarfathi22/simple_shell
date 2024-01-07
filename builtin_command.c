#include "shell.h"

/**
 * _exitt - exits the shell with or without a return of status n
 * @arv: array of words of the entered line
 */
void _exitt(char **arv)
{
	int i, n;

	if (arv[1])
	{
		n = converts_into(arv[1]);
		if (n <= -1)
			n = 2;
		free_arv(arv);
		exit(n);
	}
	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
	exit(0);
}

/**
 * converts_into - converts a string into an integer
 *@s: pointer to a string
 *Return: the integer
 */
int converts_into(char *s)
{
	int i, integer, sign = 1;

	i = 0;
	integer = 0;
	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
	{
		if (s[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (integer);
}

/**
 * print_env - prints the current environment
 * @arv: array of arguments
 */
void print_env(char **arv __attribute__ ((unused)))
{

	int i;

	for (i = 0; environ[i]; i++)
	{
		 put_str(environ[i]);
		 put_str("\n");
	}

}

/**
 * set_env - Initialize a new environment variable, or modify an existing one
 * @arv: array of entered words
 */
void set_env(char **arv)
{
	int i, j, k;

	if (!arv[1] || !arv[2])
	{
		perror(get_env("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				k = 0;
				while (arv[2][k])
				{
					environ[i][j + 1 + k] = arv[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{

		environ[i] = concat_string(arv[1], "=", arv[2]);
		environ[i + 1] = '\0';

	}
}

/**
 * un_set_env - Remove an environment variable
 * @arv: array of entered words
 */
void un_set_env(char **arv)
{
	int i, j;

	if (!arv[1])
	{
		perror(get_env("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}