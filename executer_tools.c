#include "holberton.h"

/**
 * executeLine - Executes the command entered in the child process
 * @buffer: n
 * @tokens: n
 * Return: (int) status
 */
int executeLine(char **buffer, char ***tokens)
{
	int p_child, exec, status;

	if (**buffer == '\n')
	{
		return (1);
	}

	p_child =  fork();
	if (p_child == -1)
	{
		perror("Failed to fork");
		return (-1);
	}
	if (p_child == 0)
	{
		printf("Execute line func (*tokens)[0]: %s\n", (*tokens)[0]);
		exec = execve((*tokens)[0], *tokens, NULL);
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
	return (1);
}
