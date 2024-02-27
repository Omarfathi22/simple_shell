#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>

extern char **environ;

char *Read_command_line();
char **tokenize_command(char *ln);
int execute_command(char **args, char **argv, int i);
void free_array(char **arr);

char *get_path(char *cmd);
char *get_env(char *varia);
char *_itoa(int n);
void Reverse_string(char *str, int len);

/* string function */
int string_length(char *s);
char *string_dup(const char *str);
char *string_cat(char *dest, char *str);
char *string_coy(char *dest, char *str);
void print_errors(char *nm, char *cmd, int i);

/* builtin.c */
int if_builtin_command(char *cmd);
void handle_builtin(char **cmd, char **arg, int *s, int i);
void print_environment(char **cmd, int *s);
void exit_shell(char **cmd, char **arg, int *s, int i);

int positive_num(char *s);
int _atoi(char *s);
#endif