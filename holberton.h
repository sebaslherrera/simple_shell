#ifndef PID_H
#define PID_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

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
void shellLoop(void);

/* Parser */
ssize_t readLine(char **buffer, char ***tokens);
void replaceNewLine(char **buffer);
int lenTokens(ssize_t lenReaded, char **buffer);
void processTokens(char ***tokens, char **buffer, int countToken);

/* Executer */
int executeLine(char **buffer, char ***tokens, char *fullPath);

/* String tools */
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

/* Print linked list*/
size_t print_list(const Node *h);
void free_list(Node *head);

/* Function to get the data in the interactive shell */
int _getchar(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* Get the value of a entorn variable */
char *_getenv(const char *name);
char *_getenv_local(const char *name, char **environ);

/* NOT YET */
/*int _setenv(const char *name, const char *value, int overwrite);*/

/* Get a linked list of a current entorn variable */
Node *_getpathdir(char *path);

/* Get the path into a linked list */
Node *listpath(void);

/* Return the path if found a executable */
char *addPath(char ***tokens, Node *path);

#endif
