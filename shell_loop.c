#include "holberton.h"

/**
 * shellLoop - Run the shell
 * Return: nothing
 */
void shellLoop(void)
{
	ssize_t getLine = 1;
	char **tokens = NULL, *buffer = NULL;
	int status = 0;
	Node *path = NULL;

	path = listpath();
	print_list(path);
	while (getLine != EOF)
	{
		printf("($) ");
		fflush(stdout);
		getLine = readLine(&buffer, &tokens);
		if (getLine > 0)
			status = executeLine(&buffer, &tokens);
		if (status == 1)
			printf("EXITO STATUS\n");
	}
	printf("OUT OF LOOP\n");
	free_list(path);
	free(buffer);
}
