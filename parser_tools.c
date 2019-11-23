#include "holberton.h"

/**
 * addPath - Get and check if the command is available
 * @tokens: n
 * Return: Pointer to the filename where is the path to use
 */
char *addPath(char ***tokens, Node *path)
{
	struct stat st;
	Node *pathDirs;
	char *firstOne, *copyPath = NULL;
	int lenOne, lenTwo;

	if (*tokens == NULL)
	{
		printf("TOKENS NULO\n");
		return (NULL);
	}

	pathDirs = path;
	if (pathDirs == NULL)
		return (NULL);

	firstOne = *(tokens)[0];
	lenOne = _strlen(firstOne);

	while (pathDirs != NULL)
	{
		lenTwo = _strlen(pathDirs->str);
		copyPath = malloc((lenTwo + lenOne + 2) * sizeof(char));
		if (copyPath == NULL)
			return (NULL);
		_strcat(copyPath, pathDirs->str);
		_strcat(copyPath, "/");
		_strcat(copyPath, firstOne);
		if (stat(copyPath, &st) == 0)
			break;

		free(copyPath);
		copyPath = NULL;
		pathDirs = pathDirs->next;
	}
	printf("copyPath %s\n", copyPath);
	return (copyPath);

}
/**
 * processTokens - Get all of the strings separated by a delimiter in
 * an array of strings
 * @tokens: n
 * @buffer: n
 * @countToken: n
 *
 * Return: nothing
 */
void processTokens(char ***tokens, char **buffer, int countToken)
{
	char *token = NULL;
	int i;

	*tokens = malloc(sizeof(char *) * countToken);
	token = strtok(*buffer, " ");
	for (i = 0; token != NULL; i++)
	{
		(*tokens)[i] = token;
		printf("mi token i: %d, %s\n", i, (*tokens)[i]);
		token = strtok(NULL, " ");
	}
	(*tokens)[i] = token; /*Save the NULL token*/
	printf("mi token i: %d, %s\n", i, (*tokens)[i]);
}

/**
 * lenTokens - Get the number of words separated by a delimiter
 * @lenReaded: n
 * @buffer: n
 * Return: (int) of words in the buffer
 */
int lenTokens(ssize_t lenReaded, char **buffer)
{
	char *tempToken = NULL, *copyBuffer = NULL;
	int i;

	copyBuffer = malloc(sizeof(char) * lenReaded);
	_strcpy(copyBuffer, *buffer);
	tempToken = strtok(copyBuffer, " ");
	for (i = 0; tempToken != NULL; i++)
		tempToken = strtok(NULL, " ");
	i++; /* One more to save NULL */
	free(copyBuffer);
	return (i);
}

/**
 * replaceNewLine - Replace the new line in the buffer
 * by a null character
 * @buffer: n
 * Return: nothing
 */
void replaceNewLine(char **buffer)
{
	int i;

	for (i = 0; (*buffer)[i] != '\0'; i++)
		continue;
	(*buffer)[i - 1] = '\0';  /* Replace '\n' by '\0' */

}

/**
 * readLine - Get and process the data in the stdin
 * @buffer: n
 * @tokens: n
 * Return: (ssize_t) The number of chars readed in stdin
 */
ssize_t readLine(char **buffer, char ***tokens)
{
	size_t bufferSize = 0;
	ssize_t gl;
	int countToken;

	gl = _getline(buffer, &bufferSize, stdin);

	if (gl == -1)
		printf("return of getline es -1\n");

	if (gl > 0 && **buffer != '\n')
	{
		printf("Entro al if != new line\n");
		replaceNewLine(buffer);
		countToken = lenTokens(gl, buffer);
		printf("count of tokens %d\n", countToken);
		processTokens(tokens, buffer, countToken);
	}
	return (gl);
}
