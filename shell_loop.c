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
	free(buffer);
}
