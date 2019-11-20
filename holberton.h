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

typedef struct Node
{
	char *str;
	struct Node *next;
} Node;

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

/* NOT YET */
/*int _setenv(const char *name, const char *value, int overwrite);*/

/* Get a linked list of a current entorn variable */
Node *_getpathdir(char *path);

/* Get the path into a linked list */
Node *listpath(void);

/* Return the path if found a executable */
char *addPath(char ***tokens);

#endif
