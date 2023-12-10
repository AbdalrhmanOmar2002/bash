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

/* execde.c */
char *read_user_input(void);
char **tokenize_input(char *input);
int execute_command(char **command, char **argv, char **env);

/* handle_str.c */
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/* location.c */
char *get_location(char *command);

/* utile.c */
void free_2d_arr(char **fre);

#endif
