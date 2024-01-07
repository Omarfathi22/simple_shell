#include "shell.h"

/**
 * signal_handle - checks if Ctrl C is pressed
 * @sig_num: int
 */
void signal_handle(int sig_num)
{
	if (sig_num == SIGINT)
	{
		put_str("\n#cisfun$ ");
	}
}

/**
* _EOF - handle the End of File
* @len: return value of getline function
* @buff: buffer
 */
void _EOF (int length, char *buffer)
{
	(void)buffer;
	if (length == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			put_str("\n");
			free(buffer);
		}
		exit(0);
	}
}
/**
  * _isatty - verify if terminal
  */

void fun_isatty(void)
{
	if (isatty(STDIN_FILENO))
		put_str("#cisfun$ ");
}
/**
 * main - Shell
 * Return: 0 on success
 */

int main(void)
{
	ssize_t length = 0;
	char *buffer = NULL, *value, *path_name, **arv;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, signal_handle);
	while (length != EOF)
	{
		fun_isatty();
		length = getline(&buffer, &size, stdin);
		_EOF(length, buffer);
		arv = split_str_command(buffer, " \n");
		if (!arv || !arv[0])
			 _exec(arv);
		else
		{
			value = get_env("PATH");
			head = link_path_dir(value);
			path_name = _which_path(arv[0], head);
			f = check_builtin_command(arv);
			if (f)
			{
				free(buffer);
				f(arv);
			}
			else if (!path_name)
				 _exec(arv);
			else if (path_name)
			{
				free(arv[0]);
				arv[0] = path_name;
				 _exec(arv);
			}
		}
	}
	free_list(head);
	free_arv(arv);
	free(buffer);
	return (0);
}