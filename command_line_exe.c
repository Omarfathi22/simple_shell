#include "shell.h"




/**
 * split_str_command - splits a string and makes it an array of pointers to words
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */

char **split_str_command(char *str, const char *delim)
{
	int i, wn;
	char **array;
	char *token;
	char *copy;

	copy = malloc(string_len(str) + 1);
	if (copy == NULL)
	{
		perror(get_env("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';

	token = strtok(copy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = string_dup(token);

	i = 1;
	wn = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = realloc_memory(array, (sizeof(char *) * (wn - 1)), (sizeof(char *) * wn));
		array[i] = string_dup(token);
		i++;
		wn++;
	}
	free(copy);
	return (array);
}

/**
 * _exec - executes a command
 * @argv: array of arguments
 */

void _exec(char **argv)
{

	int d, status;

	if (!argv || !argv[0])
		return;
	d = fork();
	if (d == -1)
	{
		perror(get_env("_"));
	}
	if (d == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}

/**
 * realloc_memory - Reallocates memory block
 * @ptr: previous pointer
 * @old_size: old size of previous pointer
 * @new_size: new size for our pointer
 * Return: New resized Pointer
 */

void * realloc_memory(void *ptr, unsigned int old_size_memory, unsigned int new_size_memory)
{
	char *_new;
	char *old;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size_memory));

	if (new_size_memory == old_size_memory)
		return (ptr);

	if (new_size_memory == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	_new = malloc(new_size_memory);
	old = ptr;
	if (_new == NULL)
		return (NULL);

	if (new_size_memory > old_size_memory)
	{
		for (i = 0; i < old_size_memory; i++)
			_new[i] = old[i];
		free(ptr);
		for (i = old_size_memory; i < new_size_memory; i++)
			_new[i] = '\0';
	}
	if (new_size_memory < old_size_memory)
	{
		for (i = 0; i < new_size_memory; i++)
			_new[i] = old[i];
		free(ptr);
	}
	return (_new);
}

/**
 * free_arv - frees the array of pointers arv
 *@arv: array of pointers
 */

void free_arv(char **arv)
{
	int i;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}