#include "holberton.h"

/**
 * shellLoop - Run the shell
 * Return: nothing
 */
void shellLoop(void)
{
	ssize_t getLine = 1;
	char **tokens = NULL, *buffer = NULL, *fullPath = NULL;
	char *promt = "($) ";
	/*int status = 0;*/
	Node *path = NULL;
	char *pathCopy = NULL;

	path = listpath(&pathCopy);
	while (getLine != EOF)
	{
		write(1, promt, 4); /* Print the promt */
		fflush(stdout);
		getLine = readLine(&buffer, &tokens);
		if (getLine == EOF) /* Check if it's EOF */
			break;
		fullPath = addPath(&tokens, path);
		isPath(&tokens, &fullPath);
		/*printf("fullPath: %s\n", fullPath);*/
		executeLine(&buffer, &tokens, fullPath);
		/*if (status == 1)
			printf("EXITO STATUS\n");*/
	}
	/*printf("OUT OF LOOP\n");*/
	free_list(path); /* This is a linked list with all the paths */
	free(pathCopy); /* This is on _getpathdir() environ.c */
	free(buffer); /* This is the main buffer */
	/*printf("END OF shellLop(void)\n");*/
}
