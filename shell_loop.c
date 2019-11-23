#include "holberton.h"

/**
 * shellLoop - Run the shell
 * Return: nothing
 */
void shellLoop(void)
{
	ssize_t getLine = 1;
	char **tokens = NULL, *buffer = NULL, *fullPath = NULL;
	char *promt = "($)";
	int status = 0;
	Node *path = NULL;

	path = listpath();
	while (getLine != EOF)
	{
		write(1, promt, 3);
		fflush(stdout);
		getLine = readLine(&buffer, &tokens);
		fullPath = addPath(&tokens, path);
		printf("fullPath: %s\n", fullPath);
		if (getLine > 0 && fullPath != NULL)
			status = executeLine(&buffer, &tokens, fullPath);
		else
			printf("NO ENTRO AL GETLINE >0 && FULLPATH != NULL\n");
		if (status == 1)
			printf("EXITO STATUS\n");
	}
	printf("OUT OF LOOP\n");
	free_list(path);
	free(buffer);
}
