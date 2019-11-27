#include "holberton.h"

/**
 * executeLine - Executes the command entered in the child process
 * @buffer: n
 * @tokens: n
 * @fullPath: n
 * @st: n
 * Return: (int) status
 */
int executeLine(char **buffer, char ***tokens, char *fullPath, int *st)
{
	int p_child, exec, status;

	if (*tokens == NULL)
	{	/*printf("TOKENS ES NULL executeLine()\n");*/
		return (1);
	}
	if (**buffer == '\n' || fullPath == NULL)
	{
		free(*tokens);	/*printf("NO ENTRA AL EXECUTE LINE FUNCTION\n");*/
		return (1);
	}	/*printf("ENTRO AL EXECUTE FUNCTION LiNE PRO\n");*/
	p_child =  fork();
	if (p_child == -1)
	{
		perror("Failed to fork");
		return (-1);
	}
	if (p_child == 0)
	{	/*printf("Execute line func (*tokens)[0]: %s\n", (*tokens)[0]);*/
		exec = execve(fullPath, *tokens, environ);
		if (exec == -1)
		{
			/*printf("Exec -1 \n");*/
			/*perror((*tokens)[0]);*/
			free(*tokens);
			free(*buffer);
			exit(99);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			*st = WEXITSTATUS(status); /* status code of the child */
	}
	/*printf("Before free the *tokens in exec\n");*/
	free(*tokens);
	free(fullPath); /* fullPath from addPath() or isPath() */
	return (1);
}

/**
 * isPath - some
 * @tokens: n
 * @path: n
 * @av: n
 * @count: n
 * @errShowed: n
 */
void isPath(char ***tokens, char **path, char **av, int *count, int *errShowed)
{
	char *firstOne = NULL;
	char buffer[33];
	char *msg = NULL;

	if (*path != NULL || *tokens == NULL)
		return;

	firstOne = *(tokens)[0];

	if (access(firstOne, F_OK | X_OK) == 0)
	{
		*path = _strdup(firstOne);  /* This will be free() in exec.. */
	}
	else
	{
		if (access(firstOne, F_OK) != 0)
		{
			msg = "not found\n";
			pfError(av[0], itoa(*count, buffer, 10), firstOne, msg);
			*errShowed = 127;
		}
		else if (access(firstOne, X_OK) != 0)
		{
			msg = "Permission denied\n";
			pfError(av[0], itoa(*count, buffer, 10), firstOne, msg);
			*errShowed = 126;
		}
	}
}

/**
 * isDir - some
 * @tokens: n
 * @path: n
 * @av: n
 * @count: n
 * @errShowed: n
 */
void isDir(char ***tokens, char **path, char **av, int *count, int *errShowed)
{
	struct stat st;
	char *firstOne = NULL;
	char buffer[33];
	char *msg = NULL;

	if (*tokens == NULL)
		return;

	firstOne = *(tokens)[0];

	if (stat(firstOne, &st) == 0)
	{
		if ((st.st_mode & S_IFMT) == S_IFDIR)
		{
			msg = "Permission denied\n";
			pfError(av[0], itoa(*count, buffer, 10), firstOne, msg);
			*errShowed = 126;

			if (*path != NULL)
			{
				free(*path);
				*path = NULL;
			}
		}
	}
}

