#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
/**
 * struct paths - singly linked list
 * @next: pointer to the next node
 * @str: string with a path from environment
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct paths
{
	char *str;
	struct paths *next;
} path;
void handle_sigint(int sig);
int fun_getline(char **argv, char **env, int *);
int fun_exec(char **, char **, char **);
path **_extractpath(path **head, char *);
void print_list(const path *h);
extern char **environ;
char *_getenv(char *);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
void free_grid(char **grid, int height);
void free_list(path *head);
int _strncmp(char *s1, char*s2, int len);
int _strcmp(char *s1, char*s2);
char *command(char **commands, path *list);
void handle_errors(char **, char **);
void print_env(char **);
#endif /*_HOLBERTON_H_*/
