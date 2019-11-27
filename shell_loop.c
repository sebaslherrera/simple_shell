#include "holberton.h"

/**
 * shellLoop - Run the shell
 * @argv: n
 * Return: nothing
 */
int shellLoop(char **argv)
{
	ssize_t getLine = 1;
	char **tokens = NULL, *buffer = NULL, *fullPath = NULL, *pathCopy = NULL;
	char *promt = "($) ";
	Node *path = NULL;
	int inter = 1, errorShowed = 0, counter = 1;

	path = listpath(&pathCopy);
	isatty(STDIN_FILENO) == 0 ? inter = 0 : inter;
	while (TRUE)
	{
		inter == 1 ? write(1, promt, 5) : inter; /* Print the promt */
		fflush(stdout);
		getLine = readLine(&buffer, &tokens);
		if (getLine == EOF) /* Check if it's EOF */
			break;
		errorShowed = 0;
		fullPath = addPath(&tokens, path);
		isPath(&tokens, &fullPath, argv, &counter, &errorShowed);
		isDir(&tokens, &fullPath, argv, &counter, &errorShowed);
		executeLine(&buffer, &tokens, fullPath, &errorShowed);
		counter++;
	}
	free_list(path); /* This is a linked list with all the paths */
	free(pathCopy); /* This is on _getpathdir() environ.c */
	free(buffer); /* This is the main buffer */
	return (errorShowed);
}
