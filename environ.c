#include "holberton.h"

/**
 * _getenv - some
 * @name: a
 * Return: a
 */
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
			return (&environ[i][j + 1]);
		}
	}
	return (NULL);
}

/**
 * _getpathdir - some
 * @path: a
 * @pathCopy: a
 * Return: a
 */
Node *_getpathdir(char *path, char **pathCopy)
{
	char *token = NULL;
	Node *head;
	Node *pathNode;


	if (path == NULL)
		return (NULL);

	*pathCopy = _strdup(path); /* Free on shellLoop() */

	head = NULL;
	pathNode = malloc(sizeof(Node));
	if (pathNode == NULL)
		return (NULL);

	token = strtok(*pathCopy,  ":");
	pathNode->str = token;
	pathNode->next = head;
	head = pathNode;
	while (token != NULL)
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


/**
 * listpath - Return a linked list of all directories of path
 * @pathCopy: a
 * Return: a
 */
Node *listpath(char **pathCopy)
{
	char *getEnv;
	Node *pathDirs;

	getEnv = _getenv("PATH");
	pathDirs = _getpathdir(getEnv, pathCopy);

	return (pathDirs);
}
