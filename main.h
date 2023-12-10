#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

#define PROMPT_SUCCESS "$ "
#define DELIM " \t\n"

extern char **environ;

/* execde.c */
char *read_user_input(void);
char **tokenize_input(char *input);
int execute_command(char **command, char **argv, int idx);

/* handle_str.c */
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/* location.c */
char *get_location(char *command);
char *_getenv(char *var);

/* utile.c */
void free_2d_arr(char **fre);
int is_built_in(char *command);
void handle_built_in(char **command, char **argv, int stat, int idx);
void print_env(char **command, int *status);
void exit_shell(char **command, int *status);

/* tool.c*/
void printError(char *name, char *cmd, int idx);
char *_itoa(int n);
void rev_str(char *str, int len);

#endif
