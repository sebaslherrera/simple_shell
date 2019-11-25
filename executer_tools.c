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
	/*char *originalInput = NULL;*/

	if (*tokens == NULL)
	{
		/*printf("TOKENS ES NULL executeLine()\n");*/
		return (1);
	}
	if (**buffer == '\n' || fullPath == NULL)
	{
		free(*tokens);
		/*printf("NO ENTRA AL EXECUTE LINE FUNCTION\n");*/
		return (1);
	}
	/*printf("ENTRO AL EXECUTE FUNCTION LiNE PRO\n");*/

	/*originalInput = (*tokens)[0];*/
	/*printf("original input %s\n", originalInput);*/
	(*tokens)[0] = fullPath;
	p_child =  fork();
	if (p_child == -1)
	{
		perror("Failed to fork");
		return (-1);
	}
	if (p_child == 0)
	{
		/*printf("Execute line func (*tokens)[0]: %s\n", (*tokens)[0]);*/
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
	/*printf("Before free the *tokens in exec\n");*/
	free(*tokens);
	free(fullPath); /* fullPath from addPath() or isPath() */
	return (1);
}


void isPath(char ***tokens, char **fullPath)
{
	char *firstOne = NULL;

	if (*fullPath != NULL || *tokens == NULL)
		return;

	firstOne = *(tokens)[0];

	if (access(firstOne, F_OK | X_OK) == 0)
	{
		*fullPath = _strdup(firstOne);  /* This will be free() in exec.. */
	}
	else
	{
		if(access(firstOne, F_OK) != 0)
		{
			printf("EL ARCHIVO NO EXISTE\n");
		}
		else if(access(firstOne, X_OK) != 0)
		{
			printf("NO TIENE PERM DE EJECUCION\n");
		}
	}
}
