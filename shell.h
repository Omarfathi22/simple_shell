#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int write_character(char c);
void put_str(char *str);
int string_len(char *s);
char *string_dup(char *str);
char *concat_string(char *name, char *sep, char *value);

char **split_str_command(char *str, const char *delim);
void  _exec(char **argv);
void * realloc_memory(void *ptr, unsigned int old_size, unsigned int new_size);


extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;


char *get_env(const char *name);
list_path *add_node_end(list_path **head, char *str);
list_path *link_path_dir(char *path);
char *_which_path(char *filename, list_path *head);

/**
 * struct my_build - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct my_build
{
	char *name;
	void (*func)(char **);
} my_build;

void(*check_builtin_command(char **arv))(char **arv);
int converts_into(char *s);
void _exitt(char **arv);
void print_env(char **arv);
void set_env(char **arv);
void un_set_env(char **arv);

void free_arv(char **arv);
void free_list(list_path *head);


#endif