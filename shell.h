#ifndef SHELL_H
#define SHELL_H

/*Headers used in the program*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

/*macro representing max buffer*/

#define MAXIMUM_BUFFER 1024

/*prototypes used throughout the program*/
extern char **environ;
void prime_num(int n);
void print_output(char *str);
void execute(char *input);
void display_prompt(void);
void path(char *command);
char *_strncat(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strchr(char *str, char a);
char *_strdup(char *s);
int _strcmp(char *s1, char *s2);
void _path(char *argv[]);
void _env(void);
#endif
