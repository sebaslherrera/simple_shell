#include "holberton.h"

char *_getenv(const char *name)
{
	int i, j;
	int status;


	for (i = 0; environ[i] != NULL; i++)
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				status = 0;
				break;
			}
		}

		if (status)
		{
			return (&environ[i][j+1]);
		}
	}
	return (NULL);
}

Node *_getpathdir(char *path)
{
	char *token;
	Node *head;
	Node *pathNode;

	if (path == NULL)
		return (NULL);

	head = NULL;
	pathNode = malloc(sizeof(Node));
	if (pathNode == NULL)
		return (NULL);

	token = strtok(path,  ":");
	pathNode->str = token;
	pathNode->next = head;
	head = pathNode;
	while(token != NULL)
	{
		token = strtok(NULL, ":");
		if (token == NULL) /* Don't save token NULL in list */
			break;
		pathNode = malloc(sizeof(Node));
		if (pathNode == NULL)
			return (NULL);
		pathNode->str = token;
		pathNode->next = head;
		head = pathNode;
	}

	return (head);
}


/* Return a linked list of all directories of path */
Node *listpath(void)
{
	char *getEnv;
	Node *pathDirs;

	getEnv = _getenv("PATH");
	pathDirs = _getpathdir(getEnv);

	return (pathDirs);
}
