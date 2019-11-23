#include "holberton.h"

/**
 * executeLine - Executes the command entered in the child process
 * @buffer: n
 * @tokens: n
 * Return: (int) status
 */
int executeLine(char **buffer, char ***tokens, char *fullPath)
{
	int p_child, exec, status;
	char *originalInput = NULL;
	if (**buffer == '\n' || fullPath == NULL)
	{
		printf("NO ENTRA AL EXECUTE LINE FUNCTION\n");
		return (1);
	}
	printf("ENTRO AL EXECUTE FUNCTION LiNE PRO\n");

	originalInput = (*tokens)[0];
	printf("original input %s\n", originalInput);
	(*tokens)[0] = fullPath;
	p_child =  fork();
	if (p_child == -1)
	{
		perror("Failed to fork");
		return (-1);
	}
	if (p_child == 0)
	{
		printf("Execute line func (*tokens)[0]: %s\n", (*tokens)[0]);
		exec = execve((*tokens)[0], *tokens, environ);
		if (exec == -1)
		{
			printf("Exec -1 \n");
			perror((*tokens)[0]);
			free(*tokens);
			free(*buffer);
			exit(99);
		}
	}
	else
	{
		wait(&status);
	}
	printf("Before free the *tokens in exec\n");
	free(*tokens);
	free(fullPath);
	return (1);
}
