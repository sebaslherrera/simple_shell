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
	int inter = 1;

	path = listpath(&pathCopy);
	isatty(STDIN_FILENO) == 0 ? inter = 0: inter;
	while (getLine != EOF)
	{
		inter == 1 ? write(1, promt, 4) : inter; /* Print the promt */
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
