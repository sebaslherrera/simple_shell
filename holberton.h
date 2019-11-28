#ifndef PID_H
#define PID_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define TRUE 1
#define FALSE 0

extern char **environ;

/**
 * struct Node - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct Node
{
	char *str;
	struct Node *next;
} Node;

/* Main function */
int shellLoop(char **argv);

/* Built-in function */
void isBasicExit(char ***tokens, int countToken, ssize_t *gl);
void isEnv(char ***tokens, int countToken);

/* Parser */
ssize_t readLine(char **buffer, char ***tokens);
void replaceNewLine(char **buffer);
int lenTokens(ssize_t lenReaded, char **buffer);
void processTokens(char ***tokens, char **buffer, int countToken);

/* Executer */
void isPath(char ***tokns, char **path, char **av, int *count, int *errShowed);
int executeLine(char **buffer, char ***tokens, char *fullPath, int *errShowed);

/* String tools */
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

/* Print linked list*/
size_t print_list(const Node *h);
void free_list(Node *head);

/* Function to get the data in the interactive shell */
int _getchar(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* Get the value of a entorn variable */
char *_getenv(const char *name);
char *_getenv_local(const char *name, char **environ);

/*int _setenv(const char *name, const char *value, int overwrite);*/

/* Get a linked list of a current entorn variable */
Node *_getpathdir(char *path, char **pathCopy);

/* Get the path into a linked list */
Node *listpath(char **pathCopy);

/* Return the path if found a executable */
char *addPath(char ***tokens, Node *path);

/* Prints */
void pfError(char *av, char *count, char *firstOne, char *message);
void print_error(char *str);
void _puts(int fd, char *str);

/* string-tools-adv */
char *itoa(int value, char *buffer, int base);

void isDir(char ***tokens, char **path, char **av, int *count, int *errShowed);
#endif
