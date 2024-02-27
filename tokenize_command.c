#include "shell.h"

/**
 * tokenize_command - takes the whole line and tansforms it into tokens
 *
 * @ln : the line inserted
 *
 * Return: the tokenised line
 */

char **tokenize_command(char *ln)
{
	int i = 0, j = 0;
	char **cmd = NULL;
	char *tmp = NULL, *tkn = NULL;

	tmp = string_dup(ln);
	tkn = strtok(tmp, " \n\t");
	if (!tkn)
	{
		free(ln), ln = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (tkn)
	{
		tkn = strtok(NULL, " \n\t");
		i++;
	}
	free(tmp), tmp = NULL;

	cmd = malloc(sizeof(char *) * (i + 1));
	if (!cmd)
	{
		free(ln), ln = NULL;
		return (NULL);
	}
	tkn = strtok(ln, " \n\t");
	while (tkn)
	{
		cmd[j] = string_dup(tkn);
		tkn = strtok(NULL, " \n\t");
		j++;
	}
	cmd[j] = NULL;
	free(ln), ln = NULL;
	return (cmd);
}
